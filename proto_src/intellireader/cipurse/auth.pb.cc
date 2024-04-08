// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cipurse/auth.proto

#include "cipurse/auth.pb.h"

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
namespace cipurse {
namespace auth {
class EstablishSecureChannelDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<EstablishSecureChannel> _instance;
} _EstablishSecureChannel_default_instance_;
}  // namespace auth
}  // namespace cipurse
static void InitDefaultsscc_info_EstablishSecureChannel_cipurse_2fauth_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::cipurse::auth::_EstablishSecureChannel_default_instance_;
    new (ptr) ::cipurse::auth::EstablishSecureChannel();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::cipurse::auth::EstablishSecureChannel::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EstablishSecureChannel_cipurse_2fauth_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_EstablishSecureChannel_cipurse_2fauth_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_cipurse_2fauth_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_cipurse_2fauth_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_cipurse_2fauth_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_cipurse_2fauth_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::cipurse::auth::EstablishSecureChannel, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::cipurse::auth::EstablishSecureChannel, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::cipurse::auth::EstablishSecureChannel, key_number_),
  PROTOBUF_FIELD_OFFSET(::cipurse::auth::EstablishSecureChannel, sam_key_id_),
  PROTOBUF_FIELD_OFFSET(::cipurse::auth::EstablishSecureChannel, diversification_data_),
  PROTOBUF_FIELD_OFFSET(::cipurse::auth::EstablishSecureChannel, slot_),
  PROTOBUF_FIELD_OFFSET(::cipurse::auth::EstablishSecureChannel, security_level_),
  1,
  2,
  0,
  3,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::cipurse::auth::EstablishSecureChannel)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::cipurse::auth::_EstablishSecureChannel_default_instance_),
};

const char descriptor_table_protodef_cipurse_2fauth_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022cipurse/auth.proto\022\014cipurse.auth\032\027cont"
  "act/card_slot.proto\032\034cipurse/security_le"
  "vel.proto\"\323\001\n\026EstablishSecureChannel\022\022\n\n"
  "key_number\030\001 \002(\r\022\022\n\nsam_key_id\030\002 \002(\r\022\034\n\024"
  "diversification_data\030\003 \001(\014\022)\n\004slot\030\004 \001(\016"
  "2\033.contact.card_slot.CardSlot\022H\n\016securit"
  "y_level\030\005 \001(\0162%.cipurse.security_level.S"
  "ecurityLevel:\tENCRYPTED"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_cipurse_2fauth_2eproto_deps[2] = {
  &::descriptor_table_cipurse_2fsecurity_5flevel_2eproto,
  &::descriptor_table_contact_2fcard_5fslot_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_cipurse_2fauth_2eproto_sccs[1] = {
  &scc_info_EstablishSecureChannel_cipurse_2fauth_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_cipurse_2fauth_2eproto_once;
static bool descriptor_table_cipurse_2fauth_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cipurse_2fauth_2eproto = {
  &descriptor_table_cipurse_2fauth_2eproto_initialized, descriptor_table_protodef_cipurse_2fauth_2eproto, "cipurse/auth.proto", 303,
  &descriptor_table_cipurse_2fauth_2eproto_once, descriptor_table_cipurse_2fauth_2eproto_sccs, descriptor_table_cipurse_2fauth_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_cipurse_2fauth_2eproto::offsets,
  file_level_metadata_cipurse_2fauth_2eproto, 1, file_level_enum_descriptors_cipurse_2fauth_2eproto, file_level_service_descriptors_cipurse_2fauth_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_cipurse_2fauth_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_cipurse_2fauth_2eproto), true);
namespace cipurse {
namespace auth {

// ===================================================================

void EstablishSecureChannel::InitAsDefaultInstance() {
}
class EstablishSecureChannel::_Internal {
 public:
  using HasBits = decltype(std::declval<EstablishSecureChannel>()._has_bits_);
  static void set_has_key_number(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_sam_key_id(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_diversification_data(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_slot(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_security_level(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

EstablishSecureChannel::EstablishSecureChannel()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:cipurse.auth.EstablishSecureChannel)
}
EstablishSecureChannel::EstablishSecureChannel(const EstablishSecureChannel& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  diversification_data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_diversification_data()) {
    diversification_data_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.diversification_data_);
  }
  ::memcpy(&key_number_, &from.key_number_,
    static_cast<size_t>(reinterpret_cast<char*>(&security_level_) -
    reinterpret_cast<char*>(&key_number_)) + sizeof(security_level_));
  // @@protoc_insertion_point(copy_constructor:cipurse.auth.EstablishSecureChannel)
}

void EstablishSecureChannel::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_EstablishSecureChannel_cipurse_2fauth_2eproto.base);
  diversification_data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&key_number_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&slot_) -
      reinterpret_cast<char*>(&key_number_)) + sizeof(slot_));
  security_level_ = 2;
}

EstablishSecureChannel::~EstablishSecureChannel() {
  // @@protoc_insertion_point(destructor:cipurse.auth.EstablishSecureChannel)
  SharedDtor();
}

void EstablishSecureChannel::SharedDtor() {
  diversification_data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void EstablishSecureChannel::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const EstablishSecureChannel& EstablishSecureChannel::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_EstablishSecureChannel_cipurse_2fauth_2eproto.base);
  return *internal_default_instance();
}


void EstablishSecureChannel::Clear() {
// @@protoc_insertion_point(message_clear_start:cipurse.auth.EstablishSecureChannel)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    diversification_data_.ClearNonDefaultToEmptyNoArena();
  }
  if (cached_has_bits & 0x0000001eu) {
    ::memset(&key_number_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&slot_) -
        reinterpret_cast<char*>(&key_number_)) + sizeof(slot_));
    security_level_ = 2;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* EstablishSecureChannel::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 key_number = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_key_number(&has_bits);
          key_number_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 sam_key_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_sam_key_id(&has_bits);
          sam_key_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes diversification_data = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_diversification_data();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .contact.card_slot.CardSlot slot = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::contact::card_slot::CardSlot_IsValid(val))) {
            _internal_set_slot(static_cast<::contact::card_slot::CardSlot>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(4, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional .cipurse.security_level.SecurityLevel security_level = 5 [default = ENCRYPTED];
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::cipurse::security_level::SecurityLevel_IsValid(val))) {
            _internal_set_security_level(static_cast<::cipurse::security_level::SecurityLevel>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(5, val, mutable_unknown_fields());
          }
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

::PROTOBUF_NAMESPACE_ID::uint8* EstablishSecureChannel::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:cipurse.auth.EstablishSecureChannel)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 key_number = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_key_number(), target);
  }

  // required uint32 sam_key_id = 2;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_sam_key_id(), target);
  }

  // optional bytes diversification_data = 3;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_diversification_data(), target);
  }

  // optional .contact.card_slot.CardSlot slot = 4;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      4, this->_internal_slot(), target);
  }

  // optional .cipurse.security_level.SecurityLevel security_level = 5 [default = ENCRYPTED];
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      5, this->_internal_security_level(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:cipurse.auth.EstablishSecureChannel)
  return target;
}

size_t EstablishSecureChannel::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:cipurse.auth.EstablishSecureChannel)
  size_t total_size = 0;

  if (_internal_has_key_number()) {
    // required uint32 key_number = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_key_number());
  }

  if (_internal_has_sam_key_id()) {
    // required uint32 sam_key_id = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_sam_key_id());
  }

  return total_size;
}
size_t EstablishSecureChannel::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cipurse.auth.EstablishSecureChannel)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000006) ^ 0x00000006) == 0) {  // All required fields are present.
    // required uint32 key_number = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_key_number());

    // required uint32 sam_key_id = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_sam_key_id());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional bytes diversification_data = 3;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_diversification_data());
  }

  if (cached_has_bits & 0x00000018u) {
    // optional .contact.card_slot.CardSlot slot = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_slot());
    }

    // optional .cipurse.security_level.SecurityLevel security_level = 5 [default = ENCRYPTED];
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_security_level());
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

void EstablishSecureChannel::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:cipurse.auth.EstablishSecureChannel)
  GOOGLE_DCHECK_NE(&from, this);
  const EstablishSecureChannel* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<EstablishSecureChannel>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:cipurse.auth.EstablishSecureChannel)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:cipurse.auth.EstablishSecureChannel)
    MergeFrom(*source);
  }
}

void EstablishSecureChannel::MergeFrom(const EstablishSecureChannel& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cipurse.auth.EstablishSecureChannel)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      diversification_data_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.diversification_data_);
    }
    if (cached_has_bits & 0x00000002u) {
      key_number_ = from.key_number_;
    }
    if (cached_has_bits & 0x00000004u) {
      sam_key_id_ = from.sam_key_id_;
    }
    if (cached_has_bits & 0x00000008u) {
      slot_ = from.slot_;
    }
    if (cached_has_bits & 0x00000010u) {
      security_level_ = from.security_level_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void EstablishSecureChannel::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:cipurse.auth.EstablishSecureChannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EstablishSecureChannel::CopyFrom(const EstablishSecureChannel& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cipurse.auth.EstablishSecureChannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EstablishSecureChannel::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000006) != 0x00000006) return false;
  return true;
}

void EstablishSecureChannel::InternalSwap(EstablishSecureChannel* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  diversification_data_.Swap(&other->diversification_data_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(key_number_, other->key_number_);
  swap(sam_key_id_, other->sam_key_id_);
  swap(slot_, other->slot_);
  swap(security_level_, other->security_level_);
}

::PROTOBUF_NAMESPACE_ID::Metadata EstablishSecureChannel::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace auth
}  // namespace cipurse
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::cipurse::auth::EstablishSecureChannel* Arena::CreateMaybeMessage< ::cipurse::auth::EstablishSecureChannel >(Arena* arena) {
  return Arena::CreateInternal< ::cipurse::auth::EstablishSecureChannel >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>