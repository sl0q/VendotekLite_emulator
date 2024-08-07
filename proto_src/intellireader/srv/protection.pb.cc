// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: srv/protection.proto

#include "srv/protection.pb.h"

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
namespace srv {
namespace protection {
class ActivateDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Activate> _instance;
} _Activate_default_instance_;
class DeactivateDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Deactivate> _instance;
} _Deactivate_default_instance_;
}  // namespace protection
}  // namespace srv
static void InitDefaultsscc_info_Activate_srv_2fprotection_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::srv::protection::_Activate_default_instance_;
    new (ptr) ::srv::protection::Activate();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::srv::protection::Activate::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Activate_srv_2fprotection_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Activate_srv_2fprotection_2eproto}, {}};

static void InitDefaultsscc_info_Deactivate_srv_2fprotection_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::srv::protection::_Deactivate_default_instance_;
    new (ptr) ::srv::protection::Deactivate();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::srv::protection::Deactivate::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Deactivate_srv_2fprotection_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Deactivate_srv_2fprotection_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_srv_2fprotection_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_srv_2fprotection_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_srv_2fprotection_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_srv_2fprotection_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::srv::protection::Activate, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::srv::protection::Activate, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::srv::protection::Activate, encrypted_challenge_),
  0,
  PROTOBUF_FIELD_OFFSET(::srv::protection::Deactivate, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::srv::protection::Deactivate, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::srv::protection::Activate)},
  { 7, 12, sizeof(::srv::protection::Deactivate)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::srv::protection::_Activate_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::srv::protection::_Deactivate_default_instance_),
};

const char descriptor_table_protodef_srv_2fprotection_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024srv/protection.proto\022\016srv.protection\"\'"
  "\n\010Activate\022\033\n\023encrypted_challenge\030\001 \002(\014\""
  "\014\n\nDeactivate"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_srv_2fprotection_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_srv_2fprotection_2eproto_sccs[2] = {
  &scc_info_Activate_srv_2fprotection_2eproto.base,
  &scc_info_Deactivate_srv_2fprotection_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_srv_2fprotection_2eproto_once;
static bool descriptor_table_srv_2fprotection_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_srv_2fprotection_2eproto = {
  &descriptor_table_srv_2fprotection_2eproto_initialized, descriptor_table_protodef_srv_2fprotection_2eproto, "srv/protection.proto", 93,
  &descriptor_table_srv_2fprotection_2eproto_once, descriptor_table_srv_2fprotection_2eproto_sccs, descriptor_table_srv_2fprotection_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_srv_2fprotection_2eproto::offsets,
  file_level_metadata_srv_2fprotection_2eproto, 2, file_level_enum_descriptors_srv_2fprotection_2eproto, file_level_service_descriptors_srv_2fprotection_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_srv_2fprotection_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_srv_2fprotection_2eproto), true);
namespace srv {
namespace protection {

// ===================================================================

void Activate::InitAsDefaultInstance() {
}
class Activate::_Internal {
 public:
  using HasBits = decltype(std::declval<Activate>()._has_bits_);
  static void set_has_encrypted_challenge(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

Activate::Activate()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:srv.protection.Activate)
}
Activate::Activate(const Activate& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  encrypted_challenge_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_encrypted_challenge()) {
    encrypted_challenge_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.encrypted_challenge_);
  }
  // @@protoc_insertion_point(copy_constructor:srv.protection.Activate)
}

void Activate::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Activate_srv_2fprotection_2eproto.base);
  encrypted_challenge_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Activate::~Activate() {
  // @@protoc_insertion_point(destructor:srv.protection.Activate)
  SharedDtor();
}

void Activate::SharedDtor() {
  encrypted_challenge_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Activate::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Activate& Activate::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Activate_srv_2fprotection_2eproto.base);
  return *internal_default_instance();
}


void Activate::Clear() {
// @@protoc_insertion_point(message_clear_start:srv.protection.Activate)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    encrypted_challenge_.ClearNonDefaultToEmptyNoArena();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Activate::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required bytes encrypted_challenge = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_encrypted_challenge();
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

::PROTOBUF_NAMESPACE_ID::uint8* Activate::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:srv.protection.Activate)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required bytes encrypted_challenge = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_encrypted_challenge(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:srv.protection.Activate)
  return target;
}

size_t Activate::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:srv.protection.Activate)
  size_t total_size = 0;

  // required bytes encrypted_challenge = 1;
  if (_internal_has_encrypted_challenge()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_encrypted_challenge());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Activate::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:srv.protection.Activate)
  GOOGLE_DCHECK_NE(&from, this);
  const Activate* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Activate>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:srv.protection.Activate)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:srv.protection.Activate)
    MergeFrom(*source);
  }
}

void Activate::MergeFrom(const Activate& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:srv.protection.Activate)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_encrypted_challenge()) {
    _has_bits_[0] |= 0x00000001u;
    encrypted_challenge_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.encrypted_challenge_);
  }
}

void Activate::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:srv.protection.Activate)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Activate::CopyFrom(const Activate& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:srv.protection.Activate)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Activate::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void Activate::InternalSwap(Activate* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  encrypted_challenge_.Swap(&other->encrypted_challenge_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata Activate::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Deactivate::InitAsDefaultInstance() {
}
class Deactivate::_Internal {
 public:
  using HasBits = decltype(std::declval<Deactivate>()._has_bits_);
};

Deactivate::Deactivate()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:srv.protection.Deactivate)
}
Deactivate::Deactivate(const Deactivate& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:srv.protection.Deactivate)
}

void Deactivate::SharedCtor() {
}

Deactivate::~Deactivate() {
  // @@protoc_insertion_point(destructor:srv.protection.Deactivate)
  SharedDtor();
}

void Deactivate::SharedDtor() {
}

void Deactivate::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Deactivate& Deactivate::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Deactivate_srv_2fprotection_2eproto.base);
  return *internal_default_instance();
}


void Deactivate::Clear() {
// @@protoc_insertion_point(message_clear_start:srv.protection.Deactivate)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Deactivate::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Deactivate::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:srv.protection.Deactivate)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:srv.protection.Deactivate)
  return target;
}

size_t Deactivate::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:srv.protection.Deactivate)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Deactivate::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:srv.protection.Deactivate)
  GOOGLE_DCHECK_NE(&from, this);
  const Deactivate* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Deactivate>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:srv.protection.Deactivate)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:srv.protection.Deactivate)
    MergeFrom(*source);
  }
}

void Deactivate::MergeFrom(const Deactivate& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:srv.protection.Deactivate)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void Deactivate::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:srv.protection.Deactivate)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Deactivate::CopyFrom(const Deactivate& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:srv.protection.Deactivate)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Deactivate::IsInitialized() const {
  return true;
}

void Deactivate::InternalSwap(Deactivate* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata Deactivate::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protection
}  // namespace srv
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::srv::protection::Activate* Arena::CreateMaybeMessage< ::srv::protection::Activate >(Arena* arena) {
  return Arena::CreateInternal< ::srv::protection::Activate >(arena);
}
template<> PROTOBUF_NOINLINE ::srv::protection::Deactivate* Arena::CreateMaybeMessage< ::srv::protection::Deactivate >(Arena* arena) {
  return Arena::CreateInternal< ::srv::protection::Deactivate >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
