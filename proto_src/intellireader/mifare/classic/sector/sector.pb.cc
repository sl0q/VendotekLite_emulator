// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/classic/sector/sector.proto

#include "mifare/classic/sector/sector.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_mifare_2fclassic_2fauth_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ClearKey_mifare_2fclassic_2fauth_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_mifare_2fclassic_2fauth_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_SamKey_mifare_2fclassic_2fauth_2eproto;
namespace mifare {
namespace classic {
namespace sector {
namespace sector {
class SectorDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Sector> _instance;
  const ::mifare::classic::auth::ClearKey* clear_key_;
  const ::mifare::classic::auth::SamKey* sam_key_;
} _Sector_default_instance_;
}  // namespace sector
}  // namespace sector
}  // namespace classic
}  // namespace mifare
static void InitDefaultsscc_info_Sector_mifare_2fclassic_2fsector_2fsector_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mifare::classic::sector::sector::_Sector_default_instance_;
    new (ptr) ::mifare::classic::sector::sector::Sector();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mifare::classic::sector::sector::Sector::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_Sector_mifare_2fclassic_2fsector_2fsector_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_Sector_mifare_2fclassic_2fsector_2fsector_2eproto}, {
      &scc_info_ClearKey_mifare_2fclassic_2fauth_2eproto.base,
      &scc_info_SamKey_mifare_2fclassic_2fauth_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_mifare_2fclassic_2fsector_2fsector_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_mifare_2fclassic_2fsector_2fsector_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_mifare_2fclassic_2fsector_2fsector_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_mifare_2fclassic_2fsector_2fsector_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::mifare::classic::sector::sector::Sector, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::mifare::classic::sector::sector::Sector, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::mifare::classic::sector::sector::Sector, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  offsetof(::mifare::classic::sector::sector::SectorDefaultTypeInternal, clear_key_),
  offsetof(::mifare::classic::sector::sector::SectorDefaultTypeInternal, sam_key_),
  PROTOBUF_FIELD_OFFSET(::mifare::classic::sector::sector::Sector, authentication_method_),
  ~0u,
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::mifare::classic::sector::sector::Sector)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mifare::classic::sector::sector::_Sector_default_instance_),
};

const char descriptor_table_protodef_mifare_2fclassic_2fsector_2fsector_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\"mifare/classic/sector/sector.proto\022\034mi"
  "fare.classic.sector.sector\032\031mifare/class"
  "ic/auth.proto\"\205\001\n\006Sector\0222\n\tclear_key\030\001 "
  "\001(\0132\035.mifare.classic.auth.ClearKeyH\000\022.\n\007"
  "sam_key\030\002 \001(\0132\033.mifare.classic.auth.SamK"
  "eyH\000B\027\n\025authentication_method"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_deps[1] = {
  &::descriptor_table_mifare_2fclassic_2fauth_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_sccs[1] = {
  &scc_info_Sector_mifare_2fclassic_2fsector_2fsector_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_once;
static bool descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto = {
  &descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_initialized, descriptor_table_protodef_mifare_2fclassic_2fsector_2fsector_2eproto, "mifare/classic/sector/sector.proto", 229,
  &descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_once, descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_sccs, descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_mifare_2fclassic_2fsector_2fsector_2eproto::offsets,
  file_level_metadata_mifare_2fclassic_2fsector_2fsector_2eproto, 1, file_level_enum_descriptors_mifare_2fclassic_2fsector_2fsector_2eproto, file_level_service_descriptors_mifare_2fclassic_2fsector_2fsector_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_mifare_2fclassic_2fsector_2fsector_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_mifare_2fclassic_2fsector_2fsector_2eproto), true);
namespace mifare {
namespace classic {
namespace sector {
namespace sector {

// ===================================================================

void Sector::InitAsDefaultInstance() {
  ::mifare::classic::sector::sector::_Sector_default_instance_.clear_key_ = const_cast< ::mifare::classic::auth::ClearKey*>(
      ::mifare::classic::auth::ClearKey::internal_default_instance());
  ::mifare::classic::sector::sector::_Sector_default_instance_.sam_key_ = const_cast< ::mifare::classic::auth::SamKey*>(
      ::mifare::classic::auth::SamKey::internal_default_instance());
}
class Sector::_Internal {
 public:
  using HasBits = decltype(std::declval<Sector>()._has_bits_);
  static const ::mifare::classic::auth::ClearKey& clear_key(const Sector* msg);
  static const ::mifare::classic::auth::SamKey& sam_key(const Sector* msg);
};

const ::mifare::classic::auth::ClearKey&
Sector::_Internal::clear_key(const Sector* msg) {
  return *msg->authentication_method_.clear_key_;
}
const ::mifare::classic::auth::SamKey&
Sector::_Internal::sam_key(const Sector* msg) {
  return *msg->authentication_method_.sam_key_;
}
void Sector::set_allocated_clear_key(::mifare::classic::auth::ClearKey* clear_key) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  clear_authentication_method();
  if (clear_key) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      clear_key = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, clear_key, submessage_arena);
    }
    set_has_clear_key();
    authentication_method_.clear_key_ = clear_key;
  }
  // @@protoc_insertion_point(field_set_allocated:mifare.classic.sector.sector.Sector.clear_key)
}
void Sector::clear_clear_key() {
  if (_internal_has_clear_key()) {
    delete authentication_method_.clear_key_;
    clear_has_authentication_method();
  }
}
void Sector::set_allocated_sam_key(::mifare::classic::auth::SamKey* sam_key) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  clear_authentication_method();
  if (sam_key) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      sam_key = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, sam_key, submessage_arena);
    }
    set_has_sam_key();
    authentication_method_.sam_key_ = sam_key;
  }
  // @@protoc_insertion_point(field_set_allocated:mifare.classic.sector.sector.Sector.sam_key)
}
void Sector::clear_sam_key() {
  if (_internal_has_sam_key()) {
    delete authentication_method_.sam_key_;
    clear_has_authentication_method();
  }
}
Sector::Sector()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mifare.classic.sector.sector.Sector)
}
Sector::Sector(const Sector& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  clear_has_authentication_method();
  switch (from.authentication_method_case()) {
    case kClearKey: {
      _internal_mutable_clear_key()->::mifare::classic::auth::ClearKey::MergeFrom(from._internal_clear_key());
      break;
    }
    case kSamKey: {
      _internal_mutable_sam_key()->::mifare::classic::auth::SamKey::MergeFrom(from._internal_sam_key());
      break;
    }
    case AUTHENTICATION_METHOD_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:mifare.classic.sector.sector.Sector)
}

void Sector::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Sector_mifare_2fclassic_2fsector_2fsector_2eproto.base);
  clear_has_authentication_method();
}

Sector::~Sector() {
  // @@protoc_insertion_point(destructor:mifare.classic.sector.sector.Sector)
  SharedDtor();
}

void Sector::SharedDtor() {
  if (has_authentication_method()) {
    clear_authentication_method();
  }
}

void Sector::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Sector& Sector::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Sector_mifare_2fclassic_2fsector_2fsector_2eproto.base);
  return *internal_default_instance();
}


void Sector::clear_authentication_method() {
// @@protoc_insertion_point(one_of_clear_start:mifare.classic.sector.sector.Sector)
  switch (authentication_method_case()) {
    case kClearKey: {
      delete authentication_method_.clear_key_;
      break;
    }
    case kSamKey: {
      delete authentication_method_.sam_key_;
      break;
    }
    case AUTHENTICATION_METHOD_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = AUTHENTICATION_METHOD_NOT_SET;
}


void Sector::Clear() {
// @@protoc_insertion_point(message_clear_start:mifare.classic.sector.sector.Sector)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clear_authentication_method();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Sector::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .mifare.classic.auth.ClearKey clear_key = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_clear_key(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .mifare.classic.auth.SamKey sam_key = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_sam_key(), ptr);
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
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Sector::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mifare.classic.sector.sector.Sector)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  switch (authentication_method_case()) {
    case kClearKey: {
      target = stream->EnsureSpace(target);
      target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(
          1, _Internal::clear_key(this), target, stream);
      break;
    }
    case kSamKey: {
      target = stream->EnsureSpace(target);
      target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(
          2, _Internal::sam_key(this), target, stream);
      break;
    }
    default: ;
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mifare.classic.sector.sector.Sector)
  return target;
}

size_t Sector::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mifare.classic.sector.sector.Sector)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  switch (authentication_method_case()) {
    // optional .mifare.classic.auth.ClearKey clear_key = 1;
    case kClearKey: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *authentication_method_.clear_key_);
      break;
    }
    // optional .mifare.classic.auth.SamKey sam_key = 2;
    case kSamKey: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *authentication_method_.sam_key_);
      break;
    }
    case AUTHENTICATION_METHOD_NOT_SET: {
      break;
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

void Sector::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mifare.classic.sector.sector.Sector)
  GOOGLE_DCHECK_NE(&from, this);
  const Sector* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Sector>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mifare.classic.sector.sector.Sector)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mifare.classic.sector.sector.Sector)
    MergeFrom(*source);
  }
}

void Sector::MergeFrom(const Sector& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mifare.classic.sector.sector.Sector)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  switch (from.authentication_method_case()) {
    case kClearKey: {
      _internal_mutable_clear_key()->::mifare::classic::auth::ClearKey::MergeFrom(from._internal_clear_key());
      break;
    }
    case kSamKey: {
      _internal_mutable_sam_key()->::mifare::classic::auth::SamKey::MergeFrom(from._internal_sam_key());
      break;
    }
    case AUTHENTICATION_METHOD_NOT_SET: {
      break;
    }
  }
}

void Sector::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mifare.classic.sector.sector.Sector)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Sector::CopyFrom(const Sector& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mifare.classic.sector.sector.Sector)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Sector::IsInitialized() const {
  switch (authentication_method_case()) {
    case kClearKey: {
      if (has_clear_key()) {
        if (!this->clear_key().IsInitialized()) return false;
      }
      break;
    }
    case kSamKey: {
      if (has_sam_key()) {
        if (!this->sam_key().IsInitialized()) return false;
      }
      break;
    }
    case AUTHENTICATION_METHOD_NOT_SET: {
      break;
    }
  }
  return true;
}

void Sector::InternalSwap(Sector* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(authentication_method_, other->authentication_method_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata Sector::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace sector
}  // namespace sector
}  // namespace classic
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mifare::classic::sector::sector::Sector* Arena::CreateMaybeMessage< ::mifare::classic::sector::sector::Sector >(Arena* arena) {
  return Arena::CreateInternal< ::mifare::classic::sector::sector::Sector >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
