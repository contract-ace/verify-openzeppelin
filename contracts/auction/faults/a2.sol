/// #invariant (bids[_user_1] == 0) || (bids[_user_1] != bids[_user_2]);
contract Auction {
    mapping(address => uint) bids;
    address manager;
    uint leadingBid;
    bool stopped;

    address _user_1;
    address _user_2;

    modifier canParticipate() {
        require(msg.sender != manager);
        require(!stopped);
        _;
    }

    constructor(address _m, address u1, address u2) {
        manager = _m;
        _user_1 = u1;
        _user_2 = u2;
        require(_user_1 != _user_2);
    }

    fallback () external payable {
        bid();
    }

    function bid() public payable canParticipate() {
        // (*) Fault.
        // require(msg.value > leadingBid);
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