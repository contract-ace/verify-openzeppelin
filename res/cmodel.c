#include "cmodel.h"
sol_raw_uint160_t g_literal_address_0;
int Inv_1(sol_raw_uint256_t v0, sol_raw_uint256_t v1, sol_raw_uint256_t v2,
          sol_raw_uint8_t v3, sol_raw_uint256_t v4, sol_raw_uint256_t v5,
          sol_raw_uint8_t v6, sol_raw_uint8_t v7, sol_raw_uint256_t v8) {
  return v8 <= v2;
}
struct Auction_Struct_vars1 {
  sol_bool_t user_____scribble__check__invs__at__end;
};
struct Auction_Struct_vars2 {
  sol_bool_t user_____scribble__check__invs__at__end;
};
struct Auction_Struct_vars3 {
  sol_bool_t user_____scribble__check__invs__at__end;
};
struct Map_1 {
  sol_uint256_t data_0;
  sol_uint256_t data_1;
  sol_uint256_t data_2;
  sol_uint256_t data_3;
  sol_uint256_t data_4;
  sol_uint256_t data_5;
};
struct Auction {
  sol_address_t model_address;
  sol_uint256_t model_balance;
  struct Map_1 user_bids;
  sol_address_t user_manager;
  sol_uint256_t user_leadingBid;
  sol_bool_t user_stopped;
  sol_uint256_t user___max;
  sol_uint256_t user___sum;
  sol_bool_t user___monotonic;
  sol_bool_t user_____scribble__out__of__contract;
};
struct TimedMgr {
  sol_address_t model_address;
  sol_uint256_t model_balance;
  sol_uint256_t user_start;
  sol_uint256_t user_dur;
  struct Auction user_auction;
};
sol_uint256_t sol_pay(sol_uint256_t *bal, sol_uint256_t amt) {
  sol_require(((bal)->v) >= ((amt).v), "Insufficient funds to call.");
  ((bal)->v) -= ((amt).v);
  return amt;
}
struct Auction_Struct_vars1 ZeroInit_Auction_Struct_vars1(void);
struct Auction_Struct_vars1
Init_Auction_Struct_vars1(sol_bool_t user_____scribble__check__invs__at__end);
struct Auction_Struct_vars1 ND_Auction_Struct_vars1(void);
struct Auction_Struct_vars2 ZeroInit_Auction_Struct_vars2(void);
struct Auction_Struct_vars2
Init_Auction_Struct_vars2(sol_bool_t user_____scribble__check__invs__at__end);
struct Auction_Struct_vars2 ND_Auction_Struct_vars2(void);
struct Auction_Struct_vars3 ZeroInit_Auction_Struct_vars3(void);
struct Auction_Struct_vars3
Init_Auction_Struct_vars3(sol_bool_t user_____scribble__check__invs__at__end);
struct Auction_Struct_vars3 ND_Auction_Struct_vars3(void);
struct Map_1 ZeroInit_Map_1(void);
sol_uint256_t Read_Map_1(struct Map_1 *arr, sol_address_t key_0);
void Write_Map_1(struct Map_1 *arr, sol_address_t key_0, sol_uint256_t dat);
void Auction_Fallback(struct Auction *self, sol_address_t sender,
                      sol_uint256_t value, sol_uint256_t blocknum,
                      sol_uint256_t timestamp, sol_bool_t paid,
                      sol_address_t origin);
void Auction_Method_1___original__Auction__withdraw(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin);
void Auction_Method___original__Auction__withdraw(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin);
void Auction_Method_1___original__Auction__bid(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin);
void Auction_Method___original__Auction__bid(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin);
void Auction_Method___original__Auction__stop(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin);
void Auction_Method_____scribble__Auction__check__state__invariants__internal(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin);
void Auction_Method_____scribble__check__state__invariants(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin);
void TimedMgr_Constructor(struct TimedMgr *self, sol_address_t sender,
                          sol_uint256_t value, sol_uint256_t blocknum,
                          sol_uint256_t timestamp, sol_bool_t paid,
                          sol_address_t origin, sol_uint256_t func_user___d) {
  ((self->user_start).v) = ((blocknum).v);
  ((self->user_dur).v) = ((func_user___d).v);
}
void Mgr_Constructor_For_TimedMgr(struct TimedMgr *self, sol_address_t sender,
                                  sol_uint256_t value, sol_uint256_t blocknum,
                                  sol_uint256_t timestamp, sol_bool_t paid,
                                  sol_address_t origin) {
  Init_Auction(&(self->user_auction), (self)->model_address,
               Init_sol_uint256_t(0), blocknum, timestamp, Init_sol_bool_t(1),
               origin, Init_sol_address_t(((self)->model_address).v));
}
void Init_Mgr_For_TimedMgr(struct TimedMgr *self, sol_address_t sender,
                           sol_uint256_t value, sol_uint256_t blocknum,
                           sol_uint256_t timestamp, sol_bool_t paid,
                           sol_address_t origin) {
  Mgr_Constructor_For_TimedMgr(self, sender, value, blocknum, timestamp,
                               Init_sol_bool_t(0), origin);
}
void Init_TimedMgr(struct TimedMgr *self, sol_address_t sender,
                   sol_uint256_t value, sol_uint256_t blocknum,
                   sol_uint256_t timestamp, sol_bool_t paid,
                   sol_address_t origin, sol_uint256_t user___d) {
  ((self)->model_balance) = (Init_sol_uint256_t(0));
  ((self)->user_start) = (Init_sol_uint256_t(0));
  ((self)->user_dur) = (Init_sol_uint256_t(0));
  Init_Mgr_For_TimedMgr(self, sender, value, blocknum, timestamp,
                        Init_sol_bool_t(0), origin);
  TimedMgr_Constructor(self, sender, value, blocknum, timestamp,
                       Init_sol_bool_t(0), origin, user___d);
}
void Mgr_Method_For_TimedMgr_stop(struct TimedMgr *self, sol_address_t sender,
                                  sol_uint256_t value, sol_uint256_t blocknum,
                                  sol_uint256_t timestamp, sol_bool_t paid,
                                  sol_address_t origin) {
  Auction_Method_stop(&(self->user_auction), (self)->model_address,
                      Init_sol_uint256_t(0), blocknum, timestamp,
                      Init_sol_bool_t(1), origin);
}
void TimedMgr_Method_stop(struct TimedMgr *self, sol_address_t sender,
                          sol_uint256_t value, sol_uint256_t blocknum,
                          sol_uint256_t timestamp, sol_bool_t paid,
                          sol_address_t origin) {
  sol_require((((self->user_start).v) + ((self->user_dur).v)) < ((blocknum).v),
              0);
  {
    (sender).v;
    (blocknum).v;
    sol_emit("Stopped(msg.sender, block.number)");
  }
  Mgr_Method_For_TimedMgr_stop(self, sender, value, blocknum, timestamp,
                               Init_sol_bool_t(0), origin);
}
sol_bool_t TimedMgr_Method_check(struct TimedMgr *self, sol_address_t sender,
                                 sol_uint256_t value, sol_uint256_t blocknum,
                                 sol_uint256_t timestamp, sol_bool_t paid,
                                 sol_address_t origin,
                                 sol_uint256_t *func_user_1) {
  (*(func_user_1)) = (Init_sol_uint256_t(0));
  if ((((self->user_start).v) + ((self->user_dur).v)) < ((blocknum).v)) {
    {
      (*(func_user_1)) = (Init_sol_uint256_t(
          (((blocknum).v) - ((self->user_dur).v)) - ((self->user_start).v)));
      return Init_sol_bool_t(0);
    }
  } else {
    {
      (*(func_user_1)) = (Init_sol_uint256_t(0));
      return Init_sol_bool_t(1);
    }
  }
}
struct Auction_Struct_vars1 ZeroInit_Auction_Struct_vars1(void) {
  struct Auction_Struct_vars1 tmp;
  ((tmp).user_____scribble__check__invs__at__end) = (Init_sol_bool_t(0));
  return tmp;
}
struct Auction_Struct_vars1
Init_Auction_Struct_vars1(sol_bool_t user_____scribble__check__invs__at__end) {
  struct Auction_Struct_vars1 tmp = ZeroInit_Auction_Struct_vars1();
  ((tmp).user_____scribble__check__invs__at__end) =
      (user_____scribble__check__invs__at__end);
  return tmp;
}
struct Auction_Struct_vars1 ND_Auction_Struct_vars1(void) {
  struct Auction_Struct_vars1 tmp;
  ((tmp).user_____scribble__check__invs__at__end) =
      (Init_sol_bool_t(GET_ND_RANGE(
          0, 0, 2, "Auction_Struct_vars1:__scribble_check_invs_at_end")));
  return tmp;
}
struct Auction_Struct_vars2 ZeroInit_Auction_Struct_vars2(void) {
  struct Auction_Struct_vars2 tmp;
  ((tmp).user_____scribble__check__invs__at__end) = (Init_sol_bool_t(0));
  return tmp;
}
struct Auction_Struct_vars2
Init_Auction_Struct_vars2(sol_bool_t user_____scribble__check__invs__at__end) {
  struct Auction_Struct_vars2 tmp = ZeroInit_Auction_Struct_vars2();
  ((tmp).user_____scribble__check__invs__at__end) =
      (user_____scribble__check__invs__at__end);
  return tmp;
}
struct Auction_Struct_vars2 ND_Auction_Struct_vars2(void) {
  struct Auction_Struct_vars2 tmp;
  ((tmp).user_____scribble__check__invs__at__end) =
      (Init_sol_bool_t(GET_ND_RANGE(
          1, 0, 2, "Auction_Struct_vars2:__scribble_check_invs_at_end")));
  return tmp;
}
struct Auction_Struct_vars3 ZeroInit_Auction_Struct_vars3(void) {
  struct Auction_Struct_vars3 tmp;
  ((tmp).user_____scribble__check__invs__at__end) = (Init_sol_bool_t(0));
  return tmp;
}
struct Auction_Struct_vars3
Init_Auction_Struct_vars3(sol_bool_t user_____scribble__check__invs__at__end) {
  struct Auction_Struct_vars3 tmp = ZeroInit_Auction_Struct_vars3();
  ((tmp).user_____scribble__check__invs__at__end) =
      (user_____scribble__check__invs__at__end);
  return tmp;
}
struct Auction_Struct_vars3 ND_Auction_Struct_vars3(void) {
  struct Auction_Struct_vars3 tmp;
  ((tmp).user_____scribble__check__invs__at__end) =
      (Init_sol_bool_t(GET_ND_RANGE(
          2, 0, 2, "Auction_Struct_vars3:__scribble_check_invs_at_end")));
  return tmp;
}
struct Map_1 ZeroInit_Map_1(void) {
  struct Map_1 tmp;
  ((tmp).data_0) = (Init_sol_uint256_t(0));
  ((tmp).data_1) = (Init_sol_uint256_t(0));
  ((tmp).data_2) = (Init_sol_uint256_t(0));
  ((tmp).data_3) = (Init_sol_uint256_t(0));
  ((tmp).data_4) = (Init_sol_uint256_t(0));
  ((tmp).data_5) = (Init_sol_uint256_t(0));
  return tmp;
}
sol_uint256_t Read_Map_1(struct Map_1 *arr, sol_address_t key_0) {
  {
    sol_assert((6) >= ((key_0).v), "Model failure, mapping key out of bounds.");
    if ((5) == ((key_0).v))
      return (arr)->data_5;
    else if ((4) == ((key_0).v))
      return (arr)->data_4;
    else if ((3) == ((key_0).v))
      return (arr)->data_3;
    else if ((2) == ((key_0).v))
      return (arr)->data_2;
    else if ((1) == ((key_0).v))
      return (arr)->data_1;
    else if ((0) == ((key_0).v))
      return (arr)->data_0;
  }
  return Init_sol_uint256_t(0);
}
void Write_Map_1(struct Map_1 *arr, sol_address_t key_0, sol_uint256_t dat) {
  {
    sol_assert((6) >= ((key_0).v), "Model failure, mapping key out of bounds.");
    if ((5) == ((key_0).v)) {
      ((arr)->data_5) = (dat);
    } else if ((4) == ((key_0).v)) {
      ((arr)->data_4) = (dat);
    } else if ((3) == ((key_0).v)) {
      ((arr)->data_3) = (dat);
    } else if ((2) == ((key_0).v)) {
      ((arr)->data_2) = (dat);
    } else if ((1) == ((key_0).v)) {
      ((arr)->data_1) = (dat);
    } else if ((0) == ((key_0).v)) {
      ((arr)->data_0) = (dat);
    }
  }
}
void Auction_Constructor(struct Auction *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin, sol_address_t func_user___m) {
  ((self->user_____scribble__out__of__contract).v) = (0);
  ((self->user_manager).v) = ((func_user___m).v);
  Auction_Method_____scribble__check__state__invariants(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  ((self->user_____scribble__out__of__contract).v) = (1);
}
void Init_____scribble__ReentrancyUtils_For_Auction(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  ((self)->user_____scribble__out__of__contract) = (Init_sol_bool_t(1));
}
void Init_Auction(struct Auction *self, sol_address_t sender,
                  sol_uint256_t value, sol_uint256_t blocknum,
                  sol_uint256_t timestamp, sol_bool_t paid,
                  sol_address_t origin, sol_address_t user___m) {
  ((self)->model_balance) = (Init_sol_uint256_t(0));
  ((self)->user_bids) = (ZeroInit_Map_1());
  ((self)->user_manager) = (Init_sol_address_t(0));
  ((self)->user_leadingBid) = (Init_sol_uint256_t(0));
  ((self)->user_stopped) = (Init_sol_bool_t(0));
  ((self)->user___max) = (Init_sol_uint256_t(0));
  ((self)->user___sum) = (Init_sol_uint256_t(0));
  ((self)->user___monotonic) = (Init_sol_bool_t(1));
  Init_____scribble__ReentrancyUtils_For_Auction(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  Auction_Constructor(self, sender, value, blocknum, timestamp,
                      Init_sol_bool_t(0), origin, user___m);
}
void Auction_Fallback(struct Auction *self, sol_address_t sender,
                      sol_uint256_t value, sol_uint256_t blocknum,
                      sol_uint256_t timestamp, sol_bool_t paid,
                      sol_address_t origin) {
  if (((paid).v) == (1))
    (((self)->model_balance).v) += ((value).v);
  Auction_Method_bid(self, sender, value, blocknum, timestamp,
                     Init_sol_bool_t(0), origin);
}
void Auction_Method_bid(struct Auction *self, sol_address_t sender,
                        sol_uint256_t value, sol_uint256_t blocknum,
                        sol_uint256_t timestamp, sol_bool_t paid,
                        sol_address_t origin) {
  if (((paid).v) == (1))
    (((self)->model_balance).v) += ((value).v);
  struct Auction_Struct_vars1 func_user___v;
  (((func_user___v).user_____scribble__check__invs__at__end).v) =
      ((self->user_____scribble__out__of__contract).v);
  ((self->user_____scribble__out__of__contract).v) = (0);
  Auction_Method___original__Auction__bid(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  if (((func_user___v).user_____scribble__check__invs__at__end).v)
    Auction_Method_____scribble__check__state__invariants(
        self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  ((self->user_____scribble__out__of__contract).v) =
      (((func_user___v).user_____scribble__check__invs__at__end).v);
}
void Auction_Method_withdraw(struct Auction *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin) {
  struct Auction_Struct_vars2 func_user___v;
  (((func_user___v).user_____scribble__check__invs__at__end).v) =
      ((self->user_____scribble__out__of__contract).v);
  ((self->user_____scribble__out__of__contract).v) = (0);
  Auction_Method___original__Auction__withdraw(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  if (((func_user___v).user_____scribble__check__invs__at__end).v)
    Auction_Method_____scribble__check__state__invariants(
        self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  ((self->user_____scribble__out__of__contract).v) =
      (((func_user___v).user_____scribble__check__invs__at__end).v);
}
void Auction_Method_stop(struct Auction *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin) {
  struct Auction_Struct_vars3 func_user___v;
  (((func_user___v).user_____scribble__check__invs__at__end).v) =
      ((self->user_____scribble__out__of__contract).v);
  ((self->user_____scribble__out__of__contract).v) = (0);
  Auction_Method___original__Auction__stop(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  if (((func_user___v).user_____scribble__check__invs__at__end).v)
    Auction_Method_____scribble__check__state__invariants(
        self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
  ((self->user_____scribble__out__of__contract).v) =
      (((func_user___v).user_____scribble__check__invs__at__end).v);
}
void Auction_Method_1___original__Auction__withdraw(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  sol_require(
      ((Read_Map_1(&(self->user_bids), Init_sol_address_t((sender).v))).v) !=
          ((self->user_leadingBid).v),
      0);
  sol_uint256_t func_user_pre = Init_sol_uint256_t(
      (Read_Map_1(&(self->user_bids), Init_sol_address_t((sender).v))).v);
  sol_uint256_t func_user_post = Init_sol_uint256_t(0);
  Write_Map_1(&(self->user_bids), Init_sol_address_t((sender).v),
              Init_sol_uint256_t((func_user_post).v));
  if (((func_user_post).v) >= ((self->user___max).v)) {
    ((self->user___max).v) = ((func_user_post).v);
  } else if (((func_user_pre).v) == ((self->user___max).v)) {
    ((self->user___monotonic).v) = (0);
  }
}
void Auction_Method___original__Auction__withdraw(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  sol_require(((sender).v) != ((self->user_manager).v), 0);
  sol_require(!((self->user_stopped).v), 0);
  Auction_Method_1___original__Auction__withdraw(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
}
void Auction_Method_1___original__Auction__bid(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  sol_require(((value).v) > ((self->user_leadingBid).v), 0);
  sol_uint256_t func_user_pre = Init_sol_uint256_t(
      (Read_Map_1(&(self->user_bids), Init_sol_address_t((sender).v))).v);
  sol_uint256_t func_user_post = Init_sol_uint256_t((value).v);
  Write_Map_1(&(self->user_bids), Init_sol_address_t((sender).v),
              Init_sol_uint256_t((func_user_post).v));
  if (((func_user_post).v) >= ((self->user___max).v)) {
    ((self->user___max).v) = ((func_user_post).v);
  } else if (((func_user_pre).v) == ((self->user___max).v)) {
    ((self->user___monotonic).v) = (0);
  }
  ((self->user___sum).v) =
      ((((self->user___sum).v) - ((func_user_pre).v)) + ((func_user_post).v));
  ((self->user_leadingBid).v) = ((value).v);
}
void Auction_Method___original__Auction__bid(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  sol_require(((sender).v) != ((self->user_manager).v), 0);
  sol_require(!((self->user_stopped).v), 0);
  Auction_Method_1___original__Auction__bid(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
}
void Auction_Method___original__Auction__stop(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  sol_require(((sender).v) == ((self->user_manager).v), 0);
  ((self->user_stopped).v) = (1);
}
void Auction_Method_____scribble__Auction__check__state__invariants__internal(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  {
    if (!((((self->user___monotonic).v) &&
           (((self->user___max).v) == ((self->user_leadingBid).v))) &&
          (((self->user___max).v) <= ((self->user___sum).v)))) {
      {
        1;
        sol_emit("AssertionFailed(\"0: \")");
      }
      sol_assert(0, 0);
    }
  }
}
void Auction_Method_____scribble__check__state__invariants(
    struct Auction *self, sol_address_t sender, sol_uint256_t value,
    sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
    sol_address_t origin) {
  Auction_Method_____scribble__Auction__check__state__invariants__internal(
      self, sender, value, blocknum, timestamp, Init_sol_bool_t(0), origin);
}
void run_model(void) {
  sol_address_t last_sender;
  sol_uint256_t blocknum;
  ((blocknum).v) = (GET_ND_UINT(11, 256, "blocknum"));
  sol_uint256_t timestamp;
  ((timestamp).v) = (GET_ND_UINT(12, 256, "timestamp"));
  sol_bool_t paid;
  ((paid).v) = (1);
  struct TimedMgr contract_1;
  struct Auction *contract_2;
  (g_literal_address_0) = (0);
  (((contract_1).model_address).v) = (1);
  (contract_2) = (&((contract_1).user_auction));
  (((contract_2)->model_address).v) = (2);
  (((contract_2)->user_manager).v) = (0);
  smartace_log("[Initializing contract_1 and children]");
  if (GET_ND_RANGE(15, 0, 2, "take_step")) {
    ((blocknum).v) = (GET_ND_INCREASE(13, (blocknum).v, 1, "blocknum"));
    ((timestamp).v) = (GET_ND_INCREASE(14, (timestamp).v, 1, "timestamp"));
  }
  {
    sol_address_t sender;
    ((sender).v) = (GET_ND_RANGE(16, 3, 5, "sender"));
    ((last_sender).v) = ((sender).v);
    sol_uint256_t value;
    ((value).v) = (0);
    Init_TimedMgr(&(contract_1), sender, value, blocknum, timestamp, paid,
                  sender,
                  Init_sol_uint256_t(GET_ND_UINT(17, 256, "TimedMgr:_d")));
  }
  smartace_log("[Entering transaction loop]");
  while (sol_continue()) {
    sol_on_transaction();
    if (sol_can_infer()) {
      uint64_t map_id;
      (map_id) = (GET_ND_RANGE(19, 0, 2, "map"));
      switch (map_id) {
      case 0: {
        sol_raw_uint256_t v0;
        uint64_t entry_id;
        (entry_id) = (GET_ND_RANGE(18, 0, 3, "entry"));
        switch (entry_id) {
        case 0: {
          uint8_t guard;
          (guard) = (0);
          if ((0) || ((1) && ((((contract_2)->user_manager).v) != (3))))
            (guard) = (1);
          sol_require(guard, "Guard");
          (v0) = ((((contract_2)->user_bids).data_3).v);
          break;
        }
        case 1: {
          uint8_t guard;
          (guard) = (0);
          if ((0) || ((1) && ((((contract_2)->user_manager).v) != (4))))
            (guard) = (1);
          sol_require(guard, "Guard");
          (v0) = ((((contract_2)->user_bids).data_4).v);
          break;
        }
        case 2: {
          uint8_t guard;
          (guard) = (0);
          if ((0) || ((1) && ((((contract_2)->user_manager).v) != (5))))
            (guard) = (1);
          sol_require(guard, "Guard");
          (v0) = ((((contract_2)->user_bids).data_5).v);
          break;
        }
        default: {
          sol_require(0, "Model failure, entry_id out of bounds.");
        }
        }
        sol_assert(
            Inv_1(((contract_1).user_start).v, ((contract_1).user_dur).v,
                  ((contract_2)->user_leadingBid).v,
                  ((contract_2)->user_stopped).v, ((contract_2)->user___max).v,
                  ((contract_2)->user___sum).v,
                  ((contract_2)->user___monotonic).v,
                  ((contract_2)->user_____scribble__out__of__contract).v, v0),
            0);
        break;
      }
      default: {
      }
      }
    }
    if (sol_can_infer()) {
      if ((0) || ((1) && ((((contract_2)->user_manager).v) != (3))))
        (((contract_2)->user_bids).data_3) =
            (Init_sol_uint256_t(GET_ND_UINT(20, 256, "Auction::bids::_3")));
      if ((0) || ((1) && ((((contract_2)->user_manager).v) != (3))))
        sol_require(
            Inv_1(((contract_1).user_start).v, ((contract_1).user_dur).v,
                  ((contract_2)->user_leadingBid).v,
                  ((contract_2)->user_stopped).v, ((contract_2)->user___max).v,
                  ((contract_2)->user___sum).v,
                  ((contract_2)->user___monotonic).v,
                  ((contract_2)->user_____scribble__out__of__contract).v,
                  (((contract_2)->user_bids).data_3).v),
            0);
      if ((0) || ((1) && ((((contract_2)->user_manager).v) != (4))))
        (((contract_2)->user_bids).data_4) =
            (Init_sol_uint256_t(GET_ND_UINT(21, 256, "Auction::bids::_4")));
      if ((0) || ((1) && ((((contract_2)->user_manager).v) != (4))))
        sol_require(
            Inv_1(((contract_1).user_start).v, ((contract_1).user_dur).v,
                  ((contract_2)->user_leadingBid).v,
                  ((contract_2)->user_stopped).v, ((contract_2)->user___max).v,
                  ((contract_2)->user___sum).v,
                  ((contract_2)->user___monotonic).v,
                  ((contract_2)->user_____scribble__out__of__contract).v,
                  (((contract_2)->user_bids).data_4).v),
            0);
      if ((0) || ((1) && ((((contract_2)->user_manager).v) != (5))))
        (((contract_2)->user_bids).data_5) =
            (Init_sol_uint256_t(GET_ND_UINT(22, 256, "Auction::bids::_5")));
      if ((0) || ((1) && ((((contract_2)->user_manager).v) != (5))))
        sol_require(
            Inv_1(((contract_1).user_start).v, ((contract_1).user_dur).v,
                  ((contract_2)->user_leadingBid).v,
                  ((contract_2)->user_stopped).v, ((contract_2)->user___max).v,
                  ((contract_2)->user___sum).v,
                  ((contract_2)->user___monotonic).v,
                  ((contract_2)->user_____scribble__out__of__contract).v,
                  (((contract_2)->user_bids).data_5).v),
            0);
    }
    if (GET_ND_RANGE(25, 0, 2, "take_step")) {
      ((blocknum).v) = (GET_ND_INCREASE(23, (blocknum).v, 1, "blocknum"));
      ((timestamp).v) = (GET_ND_INCREASE(24, (timestamp).v, 1, "timestamp"));
    }
    uint8_t next_call;
    (next_call) = (GET_ND_RANGE(26, 0, 6, "next_call"));
    switch (next_call) {
    case 0: {
      smartace_log("[Calling stop() on contract_1]");
      sol_address_t sender;
      ((sender).v) = (GET_ND_RANGE(3, 3, 5, "sender"));
      ((last_sender).v) = ((sender).v);
      sol_uint256_t value;
      ((value).v) = (0);
      TimedMgr_Method_stop(&(contract_1), sender, value, blocknum, timestamp,
                           paid, sender);
      smartace_log("[Call successful]");
      break;
    }
    case 1: {
      smartace_log("[Calling check() on contract_1]");
      sol_address_t sender;
      ((sender).v) = (GET_ND_RANGE(4, 3, 5, "sender"));
      ((last_sender).v) = ((sender).v);
      sol_uint256_t value;
      ((value).v) = (0);
      sol_uint256_t rv_1;
      TimedMgr_Method_check(&(contract_1), sender, value, blocknum, timestamp,
                            paid, sender, &(rv_1));
      smartace_log("[Call successful]");
      break;
    }
    case 2: {
      smartace_log("[Calling bid() on contract_2]");
      sol_address_t sender;
      ((sender).v) = (GET_ND_RANGE(5, 3, 5, "sender"));
      ((last_sender).v) = ((sender).v);
      sol_uint256_t value;
      ((value).v) = (0);
      ((value).v) = (GET_ND_UINT(6, 256, "value"));
      Auction_Method_bid(contract_2, sender, value, blocknum, timestamp, paid,
                         sender);
      smartace_log("[Call successful]");
      break;
    }
    case 3: {
      smartace_log("[Calling withdraw() on contract_2]");
      sol_address_t sender;
      ((sender).v) = (GET_ND_RANGE(7, 3, 5, "sender"));
      ((last_sender).v) = ((sender).v);
      sol_uint256_t value;
      ((value).v) = (0);
      Auction_Method_withdraw(contract_2, sender, value, blocknum, timestamp,
                              paid, sender);
      smartace_log("[Call successful]");
      break;
    }
    case 4: {
      smartace_log("[Calling stop() on contract_2]");
      sol_address_t sender;
      ((sender).v) = (GET_ND_RANGE(8, 3, 5, "sender"));
      ((last_sender).v) = ((sender).v);
      sol_uint256_t value;
      ((value).v) = (0);
      Auction_Method_stop(contract_2, sender, value, blocknum, timestamp, paid,
                          sender);
      smartace_log("[Call successful]");
      break;
    }
    case 5: {
      smartace_log("[Calling () on contract_2]");
      sol_address_t sender;
      ((sender).v) = (GET_ND_RANGE(9, 3, 5, "sender"));
      ((last_sender).v) = ((sender).v);
      sol_uint256_t value;
      ((value).v) = (0);
      ((value).v) = (GET_ND_UINT(10, 256, "value"));
      Auction_Fallback(contract_2, sender, value, blocknum, timestamp, paid,
                       sender);
      smartace_log("[Call successful]");
      break;
    }
    default: {
      sol_require(0, "Model failure, next_call out of bounds.");
    }
    }
  }
}
