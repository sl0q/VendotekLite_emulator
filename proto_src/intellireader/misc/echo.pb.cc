// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: misc/echo.proto

#include "misc/echo.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace misc {
namespace echo {
class GetEchoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GetEcho> _instance;
} _GetEcho_default_instance_;
class EchoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Echo> _instance;
} _Echo_default_instance_;
}  // namespace echo
}  // namespace misc
static void InitDefaultsscc_info_Echo_misc_2fecho_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::misc::echo::_Echo_default_instance_;
    new (ptr) ::misc::echo::Echo();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::misc::echo::Echo::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Echo_misc_2fecho_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Echo_misc_2fecho_2eproto}, {}};

static void InitDefaultsscc_info_GetEcho_misc_2fecho_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::misc::echo::_GetEcho_default_instance_;
    new (ptr) ::misc::echo::GetEcho();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::misc::echo::GetEcho::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GetEcho_misc_2fecho_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_GetEcho_misc_2fecho_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_misc_2fecho_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_misc_2fecho_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_misc_2fecho_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_misc_2fecho_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::misc::echo::GetEcho, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::misc::echo::GetEcho, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::misc::echo::GetEcho, send_pending_),
  PROTOBUF_FIELD_OFFSET(::misc::echo::GetEcho, reply_size_),
  PROTOBUF_FIELD_OFFSET(::misc::echo::GetEcho, data_),
  2,
  1,
  0,
  PROTOBUF_FIELD_OFFSET(::misc::echo::Echo, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::misc::echo::Echo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::misc::echo::Echo, echo_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::misc::echo::GetEcho)},
  { 11, 17, sizeof(::misc::echo::Echo)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::misc::echo::_GetEcho_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::misc::echo::_Echo_default_instance_),
};

const char descriptor_table_protodef_misc_2fecho_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017misc/echo.proto\022\tmisc.echo\"G\n\007GetEcho\022"
  "\032\n\014send_pending\030\001 \001(\010:\004true\022\022\n\nreply_siz"
  "e\030\002 \001(\r\022\014\n\004data\030\003 \001(\014\"\024\n\004Echo\022\014\n\004echo\030\001 "
  "\001(\014"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_misc_2fecho_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_misc_2fecho_2eproto_sccs[2] = {
  &scc_info_Echo_misc_2fecho_2eproto.base,
  &scc_info_GetEcho_misc_2fecho_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_misc_2fecho_2eproto_once;
static bool descriptor_table_misc_2fecho_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_misc_2fecho_2eproto = {
  &descriptor_table_misc_2fecho_2eproto_initialized, descriptor_table_protodef_misc_2fecho_2eproto, "misc/echo.proto", 123,
  &descriptor_table_misc_2fecho_2eproto_once, descriptor_table_misc_2fecho_2eproto_sccs, descriptor_table_misc_2fecho_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_misc_2fecho_2eproto::offsets,
  file_level_metadata_misc_2fecho_2eproto, 2, file_level_enum_descriptors_misc_2fecho_2eproto, file_level_service_descriptors_misc_2fecho_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_misc_2fecho_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_misc_2fecho_2eproto), true);
namespace misc {
namespace echo {

// ===================================================================

void GetEcho::InitAsDefaultInstance() {
}
class GetEcho::_Internal {
 public:
  using HasBits = decltype(std::declval<GetEcho>()._has_bits_);
  static void set_has_send_pending(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_reply_size(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_data(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

GetEcho::GetEcho()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:misc.echo.GetEcho)
}
GetEcho::GetEcho(const GetEcho& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_data()) {
    data_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  ::memcpy(&reply_size_, &from.reply_size_,
    static_cast<size_t>(reinterpret_cast<char*>(&send_pending_) -
    reinterpret_cast<char*>(&reply_size_)) + sizeof(send_pending_));
  // @@protoc_insertion_point(copy_constructor:misc.echo.GetEcho)
}

void GetEcho::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GetEcho_misc_2fecho_2eproto.base);
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  reply_size_ = 0u;
  send_pending_ = true;
}

GetEcho::~GetEcho() {
  // @@protoc_insertion_point(destructor:misc.echo.GetEcho)
  SharedDtor();
}

void GetEcho::SharedDtor() {
  data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void GetEcho::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GetEcho& GetEcho::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GetEcho_misc_2fecho_2eproto.base);
  return *internal_default_instance();
}


void GetEcho::Clear() {
// @@protoc_insertion_point(message_clear_start:misc.echo.GetEcho)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    data_.ClearNonDefaultToEmptyNoArena();
  }
  if (cached_has_bits & 0x00000006u) {
    reply_size_ = 0u;
    send_pending_ = true;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* GetEcho::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional bool send_pending = 1 [default = true];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_send_pending(&has_bits);
          send_pending_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 reply_size = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_reply_size(&has_bits);
          reply_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes data = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_data();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* GetEcho::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:misc.echo.GetEcho)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional bool send_pending = 1 [default = true];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_send_pending(), target);
  }

  // optional uint32 reply_size = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_reply_size(), target);
  }

  // optional bytes data = 3;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:misc.echo.GetEcho)
  return target;
}

size_t GetEcho::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:misc.echo.GetEcho)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional bytes data = 3;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_data());
    }

    // optional uint32 reply_size = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_reply_size());
    }

    // optional bool send_pending = 1 [default = true];
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 + 1;
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GetEcho::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:misc.echo.GetEcho)
  GOOGLE_DCHECK_NE(&from, this);
  const GetEcho* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GetEcho>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:misc.echo.GetEcho)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:misc.echo.GetEcho)
    MergeFrom(*source);
  }
}

void GetEcho::MergeFrom(const GetEcho& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:misc.echo.GetEcho)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      data_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.data_);
    }
    if (cached_has_bits & 0x00000002u) {
      reply_size_ = from.reply_size_;
    }
    if (cached_has_bits & 0x00000004u) {
      send_pending_ = from.send_pending_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void GetEcho::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:misc.echo.GetEcho)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetEcho::CopyFrom(const GetEcho& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:misc.echo.GetEcho)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetEcho::IsInitialized() const {
  return true;
}

void GetEcho::InternalSwap(GetEcho* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  data_.Swap(&other->data_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(reply_size_, other->reply_size_);
  swap(send_pending_, other->send_pending_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetEcho::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Echo::InitAsDefaultInstance() {
}
class Echo::_Internal {
 public:
  using HasBits = decltype(std::declval<Echo>()._has_bits_);
  static void set_has_echo(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

Echo::Echo()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:misc.echo.Echo)
}
Echo::Echo(const Echo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  echo_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_echo()) {
    echo_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.echo_);
  }
  // @@protoc_insertion_point(copy_constructor:misc.echo.Echo)
}

void Echo::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Echo_misc_2fecho_2eproto.base);
  echo_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Echo::~Echo() {
  // @@protoc_insertion_point(destructor:misc.echo.Echo)
  SharedDtor();
}

void Echo::SharedDtor() {
  echo_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Echo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Echo& Echo::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Echo_misc_2fecho_2eproto.base);
  return *internal_default_instance();
}


void Echo::Clear() {
// @@protoc_insertion_point(message_clear_start:misc.echo.Echo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    echo_.ClearNonDefaultToEmptyNoArena();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Echo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional bytes echo = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_echo();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Echo::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:misc.echo.Echo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional bytes echo = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_echo(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:misc.echo.Echo)
  return target;
}

size_t Echo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:misc.echo.Echo)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional bytes echo = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_echo());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Echo::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:misc.echo.Echo)
  GOOGLE_DCHECK_NE(&from, this);
  const Echo* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Echo>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:misc.echo.Echo)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:misc.echo.Echo)
    MergeFrom(*source);
  }
}

void Echo::MergeFrom(const Echo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:misc.echo.Echo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_echo()) {
    _has_bits_[0] |= 0x00000001u;
    echo_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.echo_);
  }
}

void Echo::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:misc.echo.Echo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Echo::CopyFrom(const Echo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:misc.echo.Echo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Echo::IsInitialized() const {
  return true;
}

void Echo::InternalSwap(Echo* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  echo_.Swap(&other->echo_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata Echo::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace echo
}  // namespace misc
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::misc::echo::GetEcho* Arena::CreateMaybeMessage< ::misc::echo::GetEcho >(Arena* arena) {
  return Arena::CreateInternal< ::misc::echo::GetEcho >(arena);
}
template<> PROTOBUF_NOINLINE ::misc::echo::Echo* Arena::CreateMaybeMessage< ::misc::echo::Echo >(Arena* arena) {
  return Arena::CreateInternal< ::misc::echo::Echo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>