contract Auction {
    mapping(address => uint) bids;
    address manager;
    uint leadingBid;
    bool stopped;

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
        bids[msg.sender] = msg.value;
        leadingBid = msg.value;
    }

    function withdraw() public canParticipate() {
        require(bids[msg.sender] != leadingBid);
        bids[msg.sender] = 0;
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