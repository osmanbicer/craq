// -*-c++-*-
/* This file was automatically generated by rpcc. */

#ifndef __RPCC_DONAR_RPC_H_INCLUDED__
#define __RPCC_DONAR_RPC_H_INCLUDED__ 1

#include "xdrmisc.h"


struct traffic_entry {
  u_int32_t server_id;
  u_int32_t update_time;
  uint64_t traffic_vol;
};
void *traffic_entry_alloc ();
bool_t xdr_traffic_entry (XDR *, void *);
RPC_STRUCT_DECL (traffic_entry)

template<class T> bool
rpc_traverse (T &t, traffic_entry &obj)
{
  return rpc_traverse (t, obj.server_id)
    && rpc_traverse (t, obj.update_time)
    && rpc_traverse (t, obj.traffic_vol);
}



struct rec_opt_info {
  rpc_str<RPC_INFINITY> content;
  uint64_t proportion;
  uint64_t epsilon;
  uint64_t cap;
  uint64_t lambda;
  rpc_vec<traffic_entry, RPC_INFINITY> entries;
};
void *rec_opt_info_alloc ();
bool_t xdr_rec_opt_info (XDR *, void *);
RPC_STRUCT_DECL (rec_opt_info)

template<class T> bool
rpc_traverse (T &t, rec_opt_info &obj)
{
  return rpc_traverse (t, obj.content)
    && rpc_traverse (t, obj.proportion)
    && rpc_traverse (t, obj.epsilon)
    && rpc_traverse (t, obj.cap)
    && rpc_traverse (t, obj.lambda)
    && rpc_traverse (t, obj.entries);
}



struct subdomain_opt {
  rpc_str<RPC_INFINITY> fqdn;
  int64_t seq_number;
  u_int32_t current_server_id;
  bool in_progress;
  rpc_vec<rec_opt_info, RPC_INFINITY> records;
};
void *subdomain_opt_alloc ();
bool_t xdr_subdomain_opt (XDR *, void *);
RPC_STRUCT_DECL (subdomain_opt)

template<class T> bool
rpc_traverse (T &t, subdomain_opt &obj)
{
  return rpc_traverse (t, obj.fqdn)
    && rpc_traverse (t, obj.seq_number)
    && rpc_traverse (t, obj.current_server_id)
    && rpc_traverse (t, obj.in_progress)
    && rpc_traverse (t, obj.records);
}


enum attr_type {
  DONAR_TTL = 1,
  LATITUDE = 2,
  LONGITUDE = 3,
  SPLIT_PROPORTION = 4,
  SPLIT_EPSILON = 5,
  BANDWIDTH_CAP = 6,
};
void *attr_type_alloc ();
bool_t xdr_attr_type (XDR *, void *);
RPC_ENUM_DECL (attr_type)
TYPE2STRUCT( , attr_type);

template<class T> inline bool
rpc_traverse (T &t, attr_type &obj)
{
  u_int32_t val = obj;
  if (!rpc_traverse (t, val))
    return false;
  obj = attr_type (val);
  return true;
}


struct record_attr {
  attr_type type;
  rpc_bytes<RPC_INFINITY> data;
};
void *record_attr_alloc ();
bool_t xdr_record_attr (XDR *, void *);
RPC_STRUCT_DECL (record_attr)

template<class T> bool
rpc_traverse (T &t, record_attr &obj)
{
  return rpc_traverse (t, obj.type)
    && rpc_traverse (t, obj.data);
}



struct record {
  rpc_str<RPC_INFINITY> type;
  rpc_str<RPC_INFINITY> content;
  int32_t ttl;
  rpc_vec<record_attr, RPC_INFINITY> attrs;
};
void *record_alloc ();
bool_t xdr_record (XDR *, void *);
RPC_STRUCT_DECL (record)

template<class T> bool
rpc_traverse (T &t, record &obj)
{
  return rpc_traverse (t, obj.type)
    && rpc_traverse (t, obj.content)
    && rpc_traverse (t, obj.ttl)
    && rpc_traverse (t, obj.attrs);
}



struct subdomain {
  rpc_str<RPC_INFINITY> fqdn;
  int64_t seq_number;
  rpc_vec<record, RPC_INFINITY> records;
  rpc_opaque<20> account_hash;
};
void *subdomain_alloc ();
bool_t xdr_subdomain (XDR *, void *);
RPC_STRUCT_DECL (subdomain)

template<class T> bool
rpc_traverse (T &t, subdomain &obj)
{
  return rpc_traverse (t, obj.fqdn)
    && rpc_traverse (t, obj.seq_number)
    && rpc_traverse (t, obj.records)
    && rpc_traverse (t, obj.account_hash);
}



struct account {
  rpc_opaque<20> key_hash;
  int64_t seq_num;
  rpc_str<RPC_INFINITY> suffix;
  int64_t last_update;
  int32_t soa_ttl;
  rpc_str<RPC_INFINITY> contact_email;
  rpc_vec<subdomain, RPC_INFINITY> subdomains;
};
void *account_alloc ();
bool_t xdr_account (XDR *, void *);
RPC_STRUCT_DECL (account)

template<class T> bool
rpc_traverse (T &t, account &obj)
{
  return rpc_traverse (t, obj.key_hash)
    && rpc_traverse (t, obj.seq_num)
    && rpc_traverse (t, obj.suffix)
    && rpc_traverse (t, obj.last_update)
    && rpc_traverse (t, obj.soa_ttl)
    && rpc_traverse (t, obj.contact_email)
    && rpc_traverse (t, obj.subdomains);
}

#endif /* !__RPCC_DONAR_RPC_H_INCLUDED__ */
