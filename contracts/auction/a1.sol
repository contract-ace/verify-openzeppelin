/// #invariant _monotonic && (_max == leadingBid) && (_max <= _sum);
contract Auction {
    mapping(address => uint) bids;
    address manager;
    uint leadingBid;
    bool stopped;

    uint _max = 0;
    uint _sum = 0;
    bool _monotonic = true;

    modifier canParticipate() {
        require(msg.sender != manager);
        require(!stopped);
        _;
    }

    constructor(address _m) {
        manager = _m;
    }

    fallback () external payable {
        bid();
    }

    function bid() public payable canParticipate() {
        require(msg.value > leadingBid);
        // [Start:Instrumented]
            uint pre = bids[msg.sender];
            uint post = msg.value;
            bids[msg.sender] = post;
            if (post >= _max) { _max = post; }
            else if (pre == _max) { _monotonic = false; }
            _sum = _sum - pre + post;
        // [End:Instrumented]
        leadingBid = msg.value;
    }

    function withdraw() public canParticipate() {
        require(bids[msg.sender] != leadingBid);
        // [Start:Instrumented]
            uint pre = bids[msg.sender];
            uint post = 0;
            bids[msg.sender] = post;
            if (post >= _max) { _max = post; }
            else if (pre == _max) { _monotonic = false; }
        // [End:Instrumented]
    }

    function stop() public {
        require(msg.sender == manager);
        stopped = true;
    }
}

contract Mgr {
    Auction auction;
  
    constructor() {
        auction = new Auction(address(this));
    }

    function stop() public virtual {
        auction.stop();
    }
}

contract TimedMgr is Mgr {
    event Stopped(address _by, uint _block);

    uint start;
    uint dur;
  
    constructor(uint _d) {
        start = block.number;
        dur = _d;
    }

    function stop() public override {
        require(start + dur < block.number);
        emit Stopped(msg.sender, block.number);
        super.stop();
    }

    function check() public view returns (bool, uint) {
        if (start + dur < block.number) {
            return (false, block.number - dur - start);
        }
        else {
            return (true, 0);
        }
    }
}