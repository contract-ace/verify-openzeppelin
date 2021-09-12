// Obtained from OpenZeppelin: https://github.com/OpenZeppelin/openzeppelin-contracts

contract Context {
    function _msgSender() internal view virtual returns (address) {
        return msg.sender;
    }

// (*) Removed due to Solidity version in SmartACE.
//    function _msgData() internal view virtual returns (bytes calldata) {
//        return msg.data;
//    }
}

contract Ownable is Context {
    address private _owner;

    event OwnershipTransferred(address indexed previousOwner, address indexed newOwner);

    constructor() {
        _setOwner(_msgSender());
    }

    function owner() public view virtual returns (address) {
        return _owner;
    }

    modifier onlyOwner() {
        require(owner() == _msgSender(), "Ownable: caller is not the owner");
        _;
    }

    function renounceOwnership() public virtual onlyOwner {
        _setOwner(address(0));
    }

    function transferOwnership(address newOwner) public virtual onlyOwner {
        require(newOwner != address(0), "Ownable: new owner is the zero address");
        _setOwner(newOwner);
    }

    function _setOwner(address newOwner) private {
        address oldOwner = _owner;
        _owner = newOwner;
        emit OwnershipTransferred(oldOwner, newOwner);
    }
}

contract Escrow is Ownable {
    // (*) Removed due to Solidity version in SmartACE.
    // using Address for address payable;

    event Deposited(address indexed payee, uint256 weiAmount);
    event Withdrawn(address indexed payee, uint256 weiAmount);

    mapping(address => uint256) private _deposits;

    function depositsOf(address payee) public view returns (uint256) {
        return _deposits[payee];
    }

    function deposit(address payee) public payable virtual onlyOwner {
        uint256 amount = msg.value;
        _deposits[payee] += amount;
        emit Deposited(payee, amount);
    }

    function withdraw(address payable payee) public virtual onlyOwner {
        uint256 payment = _deposits[payee];

        _deposits[payee] = 0;

        // (*) Changed due to Solidity version in SmartACE.
        // payee.sendValue(payment);
        payee.transfer(payment);

        emit Withdrawn(payee, payment);
    }
}

// (*) Changed due to Solidity version in SmartACE.
// abstract contract ConditionalEscrow is Escrow {
contract ConditionalEscrow is Escrow {
    // (*) Changed due to Solidity version in SmartACE.
    // function withdrawalAllowed(address payee) public view virtual returns (bool);
    function withdrawalAllowed(address) public view virtual returns (bool) {
        return true;
    }

    function withdraw(address payable payee) public virtual override {
        require(withdrawalAllowed(payee), "ConditionalEscrow: payee is not allowed to withdraw");
        super.withdraw(payee);
    }
}

contract RefundEscrow is ConditionalEscrow {
    // (*) Removed due to Solidity version in SmartACE.
    // using Address for address payable;

    enum State {
        Active,
        Refunding,
        Closed
    }

    event RefundsClosed();
    event RefundsEnabled();

    State private _state;
    address payable private immutable _beneficiary;

    constructor(address payable beneficiary_) {
        require(beneficiary_ != address(0), "RefundEscrow: beneficiary is the zero address");
        _beneficiary = beneficiary_;
        _state = State.Active;
    }

    function state() public view virtual returns (State) {
        return _state;
    }

    function beneficiary() public view virtual returns (address payable) {
        return _beneficiary;
    }

    function deposit(address refundee) public payable virtual override {
        require(state() == State.Active, "RefundEscrow: can only deposit while active");
        super.deposit(refundee);
    }

    function close() public virtual onlyOwner {
        require(state() == State.Active, "RefundEscrow: can only close while active");
        _state = State.Closed;
        emit RefundsClosed();
    }

    function enableRefunds() public virtual onlyOwner {
        require(state() == State.Active, "RefundEscrow: can only enable refunds while active");
        _state = State.Refunding;
        emit RefundsEnabled();
    }

    function beneficiaryWithdraw() public virtual {
        require(state() == State.Closed, "RefundEscrow: beneficiary can only withdraw while closed");
        // (*) Changed due to Solidity version in SmartACE.
        // beneficiary().sendValue(address(this).balance);
        beneficiary().transfer(address(this).balance);
    }

    function withdrawalAllowed(address) public view override returns (bool) {
        return state() == State.Refunding;
    }
}