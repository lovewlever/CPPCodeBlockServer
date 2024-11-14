// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UserInfo.proto

#include "UserInfo.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace gq {

inline constexpr UserInfo::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : user_name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        user_account_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        user_pwd_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        id_{0},
        is_admin_{0},
        ss_mt_{0},
        ss_mdi_{0},
        ss_mcb_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR UserInfo::UserInfo(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct UserInfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR UserInfoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~UserInfoDefaultTypeInternal() {}
  union {
    UserInfo _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UserInfoDefaultTypeInternal _UserInfo_default_instance_;

inline constexpr ResultData::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : msg_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        code_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ResultData::ResultData(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ResultDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResultDataDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResultDataDefaultTypeInternal() {}
  union {
    ResultData _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResultDataDefaultTypeInternal _ResultData_default_instance_;
}  // namespace gq
static ::_pb::Metadata file_level_metadata_UserInfo_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_UserInfo_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_UserInfo_2eproto = nullptr;
const ::uint32_t TableStruct_UserInfo_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.id_),
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.user_name_),
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.user_account_),
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.user_pwd_),
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.is_admin_),
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.ss_mt_),
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.ss_mdi_),
    PROTOBUF_FIELD_OFFSET(::gq::UserInfo, _impl_.ss_mcb_),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::gq::ResultData, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::gq::ResultData, _impl_.code_),
    PROTOBUF_FIELD_OFFSET(::gq::ResultData, _impl_.msg_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::gq::UserInfo)},
        {16, -1, -1, sizeof(::gq::ResultData)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::gq::_UserInfo_default_instance_._instance,
    &::gq::_ResultData_default_instance_._instance,
};
const char descriptor_table_protodef_UserInfo_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\016UserInfo.proto\022\002gq\"\222\001\n\010UserInfo\022\n\n\002id\030"
    "\001 \001(\005\022\021\n\tuser_name\030\002 \001(\t\022\024\n\014user_account"
    "\030\003 \001(\t\022\020\n\010user_pwd\030\004 \001(\t\022\020\n\010is_admin\030\005 \001"
    "(\005\022\r\n\005ss_mt\030\006 \001(\005\022\016\n\006ss_mdi\030\007 \001(\005\022\016\n\006ss_"
    "mcb\030\010 \001(\005\"\'\n\nResultData\022\014\n\004code\030\001 \001(\005\022\013\n"
    "\003msg\030\002 \001(\tb\006proto3"
};
static ::absl::once_flag descriptor_table_UserInfo_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_UserInfo_2eproto = {
    false,
    false,
    218,
    descriptor_table_protodef_UserInfo_2eproto,
    "UserInfo.proto",
    &descriptor_table_UserInfo_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_UserInfo_2eproto::offsets,
    file_level_metadata_UserInfo_2eproto,
    file_level_enum_descriptors_UserInfo_2eproto,
    file_level_service_descriptors_UserInfo_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_UserInfo_2eproto_getter() {
  return &descriptor_table_UserInfo_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_UserInfo_2eproto(&descriptor_table_UserInfo_2eproto);
namespace gq {
// ===================================================================

class UserInfo::_Internal {
 public:
};

UserInfo::UserInfo(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:gq.UserInfo)
}
inline PROTOBUF_NDEBUG_INLINE UserInfo::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : user_name_(arena, from.user_name_),
        user_account_(arena, from.user_account_),
        user_pwd_(arena, from.user_pwd_),
        _cached_size_{0} {}

UserInfo::UserInfo(
    ::google::protobuf::Arena* arena,
    const UserInfo& from)
    : ::google::protobuf::Message(arena) {
  UserInfo* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, id_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, id_),
           offsetof(Impl_, ss_mcb_) -
               offsetof(Impl_, id_) +
               sizeof(Impl_::ss_mcb_));

  // @@protoc_insertion_point(copy_constructor:gq.UserInfo)
}
inline PROTOBUF_NDEBUG_INLINE UserInfo::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : user_name_(arena),
        user_account_(arena),
        user_pwd_(arena),
        _cached_size_{0} {}

inline void UserInfo::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, id_),
           0,
           offsetof(Impl_, ss_mcb_) -
               offsetof(Impl_, id_) +
               sizeof(Impl_::ss_mcb_));
}
UserInfo::~UserInfo() {
  // @@protoc_insertion_point(destructor:gq.UserInfo)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void UserInfo::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.user_name_.Destroy();
  _impl_.user_account_.Destroy();
  _impl_.user_pwd_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void UserInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:gq.UserInfo)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.user_name_.ClearToEmpty();
  _impl_.user_account_.ClearToEmpty();
  _impl_.user_pwd_.ClearToEmpty();
  ::memset(&_impl_.id_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.ss_mcb_) -
      reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.ss_mcb_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* UserInfo::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 8, 0, 57, 2> UserInfo::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    8, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967040,  // skipmap
    offsetof(decltype(_table_), field_entries),
    8,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_UserInfo_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // int32 ss_mcb = 8;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(UserInfo, _impl_.ss_mcb_), 63>(),
     {64, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.ss_mcb_)}},
    // int32 id = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(UserInfo, _impl_.id_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.id_)}},
    // string user_name = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.user_name_)}},
    // string user_account = 3;
    {::_pbi::TcParser::FastUS1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.user_account_)}},
    // string user_pwd = 4;
    {::_pbi::TcParser::FastUS1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.user_pwd_)}},
    // int32 is_admin = 5;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(UserInfo, _impl_.is_admin_), 63>(),
     {40, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.is_admin_)}},
    // int32 ss_mt = 6;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(UserInfo, _impl_.ss_mt_), 63>(),
     {48, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.ss_mt_)}},
    // int32 ss_mdi = 7;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(UserInfo, _impl_.ss_mdi_), 63>(),
     {56, 63, 0, PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.ss_mdi_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int32 id = 1;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // string user_name = 2;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.user_name_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string user_account = 3;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.user_account_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string user_pwd = 4;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.user_pwd_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // int32 is_admin = 5;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.is_admin_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // int32 ss_mt = 6;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.ss_mt_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // int32 ss_mdi = 7;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.ss_mdi_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // int32 ss_mcb = 8;
    {PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.ss_mcb_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
    "\13\0\11\14\10\0\0\0\0\0\0\0\0\0\0\0"
    "gq.UserInfo"
    "user_name"
    "user_account"
    "user_pwd"
  }},
};

::uint8_t* UserInfo::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:gq.UserInfo)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // int32 id = 1;
  if (this->_internal_id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_id(), target);
  }

  // string user_name = 2;
  if (!this->_internal_user_name().empty()) {
    const std::string& _s = this->_internal_user_name();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "gq.UserInfo.user_name");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // string user_account = 3;
  if (!this->_internal_user_account().empty()) {
    const std::string& _s = this->_internal_user_account();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "gq.UserInfo.user_account");
    target = stream->WriteStringMaybeAliased(3, _s, target);
  }

  // string user_pwd = 4;
  if (!this->_internal_user_pwd().empty()) {
    const std::string& _s = this->_internal_user_pwd();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "gq.UserInfo.user_pwd");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  // int32 is_admin = 5;
  if (this->_internal_is_admin() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<5>(
            stream, this->_internal_is_admin(), target);
  }

  // int32 ss_mt = 6;
  if (this->_internal_ss_mt() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<6>(
            stream, this->_internal_ss_mt(), target);
  }

  // int32 ss_mdi = 7;
  if (this->_internal_ss_mdi() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<7>(
            stream, this->_internal_ss_mdi(), target);
  }

  // int32 ss_mcb = 8;
  if (this->_internal_ss_mcb() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<8>(
            stream, this->_internal_ss_mcb(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gq.UserInfo)
  return target;
}

::size_t UserInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:gq.UserInfo)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string user_name = 2;
  if (!this->_internal_user_name().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_user_name());
  }

  // string user_account = 3;
  if (!this->_internal_user_account().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_user_account());
  }

  // string user_pwd = 4;
  if (!this->_internal_user_pwd().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_user_pwd());
  }

  // int32 id = 1;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_id());
  }

  // int32 is_admin = 5;
  if (this->_internal_is_admin() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_is_admin());
  }

  // int32 ss_mt = 6;
  if (this->_internal_ss_mt() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_ss_mt());
  }

  // int32 ss_mdi = 7;
  if (this->_internal_ss_mdi() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_ss_mdi());
  }

  // int32 ss_mcb = 8;
  if (this->_internal_ss_mcb() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_ss_mcb());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData UserInfo::_class_data_ = {
    UserInfo::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* UserInfo::GetClassData() const {
  return &_class_data_;
}

void UserInfo::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<UserInfo*>(&to_msg);
  auto& from = static_cast<const UserInfo&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:gq.UserInfo)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_user_name().empty()) {
    _this->_internal_set_user_name(from._internal_user_name());
  }
  if (!from._internal_user_account().empty()) {
    _this->_internal_set_user_account(from._internal_user_account());
  }
  if (!from._internal_user_pwd().empty()) {
    _this->_internal_set_user_pwd(from._internal_user_pwd());
  }
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  if (from._internal_is_admin() != 0) {
    _this->_internal_set_is_admin(from._internal_is_admin());
  }
  if (from._internal_ss_mt() != 0) {
    _this->_internal_set_ss_mt(from._internal_ss_mt());
  }
  if (from._internal_ss_mdi() != 0) {
    _this->_internal_set_ss_mdi(from._internal_ss_mdi());
  }
  if (from._internal_ss_mcb() != 0) {
    _this->_internal_set_ss_mcb(from._internal_ss_mcb());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void UserInfo::CopyFrom(const UserInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:gq.UserInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool UserInfo::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* UserInfo::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void UserInfo::InternalSwap(UserInfo* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.user_name_, &other->_impl_.user_name_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.user_account_, &other->_impl_.user_account_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.user_pwd_, &other->_impl_.user_pwd_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.ss_mcb_)
      + sizeof(UserInfo::_impl_.ss_mcb_)
      - PROTOBUF_FIELD_OFFSET(UserInfo, _impl_.id_)>(
          reinterpret_cast<char*>(&_impl_.id_),
          reinterpret_cast<char*>(&other->_impl_.id_));
}

::google::protobuf::Metadata UserInfo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_UserInfo_2eproto_getter, &descriptor_table_UserInfo_2eproto_once,
      file_level_metadata_UserInfo_2eproto[0]);
}
// ===================================================================

class ResultData::_Internal {
 public:
};

ResultData::ResultData(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:gq.ResultData)
}
inline PROTOBUF_NDEBUG_INLINE ResultData::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : msg_(arena, from.msg_),
        _cached_size_{0} {}

ResultData::ResultData(
    ::google::protobuf::Arena* arena,
    const ResultData& from)
    : ::google::protobuf::Message(arena) {
  ResultData* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  _impl_.code_ = from._impl_.code_;

  // @@protoc_insertion_point(copy_constructor:gq.ResultData)
}
inline PROTOBUF_NDEBUG_INLINE ResultData::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : msg_(arena),
        _cached_size_{0} {}

inline void ResultData::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.code_ = {};
}
ResultData::~ResultData() {
  // @@protoc_insertion_point(destructor:gq.ResultData)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void ResultData::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.msg_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void ResultData::Clear() {
// @@protoc_insertion_point(message_clear_start:gq.ResultData)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.msg_.ClearToEmpty();
  _impl_.code_ = 0;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* ResultData::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 25, 2> ResultData::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_ResultData_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string msg = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(ResultData, _impl_.msg_)}},
    // int32 code = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(ResultData, _impl_.code_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(ResultData, _impl_.code_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int32 code = 1;
    {PROTOBUF_FIELD_OFFSET(ResultData, _impl_.code_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // string msg = 2;
    {PROTOBUF_FIELD_OFFSET(ResultData, _impl_.msg_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\15\0\3\0\0\0\0\0"
    "gq.ResultData"
    "msg"
  }},
};

::uint8_t* ResultData::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:gq.ResultData)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // int32 code = 1;
  if (this->_internal_code() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_code(), target);
  }

  // string msg = 2;
  if (!this->_internal_msg().empty()) {
    const std::string& _s = this->_internal_msg();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "gq.ResultData.msg");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gq.ResultData)
  return target;
}

::size_t ResultData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:gq.ResultData)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string msg = 2;
  if (!this->_internal_msg().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_msg());
  }

  // int32 code = 1;
  if (this->_internal_code() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_code());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData ResultData::_class_data_ = {
    ResultData::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* ResultData::GetClassData() const {
  return &_class_data_;
}

void ResultData::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<ResultData*>(&to_msg);
  auto& from = static_cast<const ResultData&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:gq.ResultData)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_msg().empty()) {
    _this->_internal_set_msg(from._internal_msg());
  }
  if (from._internal_code() != 0) {
    _this->_internal_set_code(from._internal_code());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ResultData::CopyFrom(const ResultData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:gq.ResultData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool ResultData::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* ResultData::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void ResultData::InternalSwap(ResultData* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.msg_, &other->_impl_.msg_, arena);
        swap(_impl_.code_, other->_impl_.code_);
}

::google::protobuf::Metadata ResultData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_UserInfo_2eproto_getter, &descriptor_table_UserInfo_2eproto_once,
      file_level_metadata_UserInfo_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace gq
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"