// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/av2/args.proto

#include "mifare/av2/args.pb.h"

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
namespace mifare {
namespace av2 {
namespace args {
class AuthenticationArgumentsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<AuthenticationArguments> _instance;
} _AuthenticationArguments_default_instance_;
}  // namespace args
}  // namespace av2
}  // namespace mifare
static void InitDefaultsscc_info_AuthenticationArguments_mifare_2fav2_2fargs_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mifare::av2::args::_AuthenticationArguments_default_instance_;
    new (ptr) ::mifare::av2::args::AuthenticationArguments();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mifare::av2::args::AuthenticationArguments::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_AuthenticationArguments_mifare_2fav2_2fargs_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_AuthenticationArguments_mifare_2fav2_2fargs_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_mifare_2fav2_2fargs_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_mifare_2fav2_2fargs_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_mifare_2fav2_2fargs_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_mifare_2fav2_2fargs_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::mifare::av2::args::AuthenticationArguments, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::mifare::av2::args::AuthenticationArguments, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mifare::av2::args::AuthenticationArguments, slot_),
  PROTOBUF_FIELD_OFFSET(::mifare::av2::args::AuthenticationArguments, key_number_),
  PROTOBUF_FIELD_OFFSET(::mifare::av2::args::AuthenticationArguments, key_version_),
  PROTOBUF_FIELD_OFFSET(::mifare::av2::args::AuthenticationArguments, channel_),
  0,
  1,
  2,
  3,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::mifare::av2::args::AuthenticationArguments)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mifare::av2::args::_AuthenticationArguments_default_instance_),
};

const char descriptor_table_protodef_mifare_2fav2_2fargs_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025mifare/av2/args.proto\022\017mifare.av2.args"
  "\032\027contact/card_slot.proto\032\030mifare/av2/ch"
  "annel.proto\"\255\001\n\027AuthenticationArguments\022"
  ")\n\004slot\030\001 \002(\0162\033.contact.card_slot.CardSl"
  "ot\022\022\n\nkey_number\030\002 \002(\r\022\026\n\013key_version\030\003 "
  "\001(\r:\0010\022;\n\007channel\030\004 \001(\0162\033.mifare.av2.cha"
  "nnel.Channel:\rAV2_CHANNEL_0"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_mifare_2fav2_2fargs_2eproto_deps[2] = {
  &::descriptor_table_contact_2fcard_5fslot_2eproto,
  &::descriptor_table_mifare_2fav2_2fchannel_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_mifare_2fav2_2fargs_2eproto_sccs[1] = {
  &scc_info_AuthenticationArguments_mifare_2fav2_2fargs_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_mifare_2fav2_2fargs_2eproto_once;
static bool descriptor_table_mifare_2fav2_2fargs_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fav2_2fargs_2eproto = {
  &descriptor_table_mifare_2fav2_2fargs_2eproto_initialized, descriptor_table_protodef_mifare_2fav2_2fargs_2eproto, "mifare/av2/args.proto", 267,
  &descriptor_table_mifare_2fav2_2fargs_2eproto_once, descriptor_table_mifare_2fav2_2fargs_2eproto_sccs, descriptor_table_mifare_2fav2_2fargs_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_mifare_2fav2_2fargs_2eproto::offsets,
  file_level_metadata_mifare_2fav2_2fargs_2eproto, 1, file_level_enum_descriptors_mifare_2fav2_2fargs_2eproto, file_level_service_descriptors_mifare_2fav2_2fargs_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_mifare_2fav2_2fargs_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_mifare_2fav2_2fargs_2eproto), true);
namespace mifare {
namespace av2 {
namespace args {

// ===================================================================

void AuthenticationArguments::InitAsDefaultInstance() {
}
class AuthenticationArguments::_Internal {
 public:
  using HasBits = decltype(std::declval<AuthenticationArguments>()._has_bits_);
  static void set_has_slot(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_key_number(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_key_version(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_channel(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
};

AuthenticationArguments::AuthenticationArguments()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mifare.av2.args.AuthenticationArguments)
}
AuthenticationArguments::AuthenticationArguments(const AuthenticationArguments& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&slot_, &from.slot_,
    static_cast<size_t>(reinterpret_cast<char*>(&channel_) -
    reinterpret_cast<char*>(&slot_)) + sizeof(channel_));
  // @@protoc_insertion_point(copy_constructor:mifare.av2.args.AuthenticationArguments)
}

void AuthenticationArguments::SharedCtor() {
  ::memset(&slot_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&channel_) -
      reinterpret_cast<char*>(&slot_)) + sizeof(channel_));
}

AuthenticationArguments::~AuthenticationArguments() {
  // @@protoc_insertion_point(destructor:mifare.av2.args.AuthenticationArguments)
  SharedDtor();
}

void AuthenticationArguments::SharedDtor() {
}

void AuthenticationArguments::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const AuthenticationArguments& AuthenticationArguments::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_AuthenticationArguments_mifare_2fav2_2fargs_2eproto.base);
  return *internal_default_instance();
}


void AuthenticationArguments::Clear() {
// @@protoc_insertion_point(message_clear_start:mifare.av2.args.AuthenticationArguments)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    ::memset(&slot_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&channel_) -
        reinterpret_cast<char*>(&slot_)) + sizeof(channel_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* AuthenticationArguments::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required .contact.card_slot.CardSlot slot = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::contact::card_slot::CardSlot_IsValid(val))) {
            _internal_set_slot(static_cast<::contact::card_slot::CardSlot>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // required uint32 key_number = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_key_number(&has_bits);
          key_number_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 key_version = 3 [default = 0];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_key_version(&has_bits);
          key_version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .mifare.av2.channel.Channel channel = 4 [default = AV2_CHANNEL_0];
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::mifare::av2::channel::Channel_IsValid(val))) {
            _internal_set_channel(static_cast<::mifare::av2::channel::Channel>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(4, val, mutable_unknown_fields());
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

::PROTOBUF_NAMESPACE_ID::uint8* AuthenticationArguments::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mifare.av2.args.AuthenticationArguments)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .contact.card_slot.CardSlot slot = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_slot(), target);
  }

  // required uint32 key_number = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_key_number(), target);
  }

  // optional uint32 key_version = 3 [default = 0];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_key_version(), target);
  }

  // optional .mifare.av2.channel.Channel channel = 4 [default = AV2_CHANNEL_0];
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      4, this->_internal_channel(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mifare.av2.args.AuthenticationArguments)
  return target;
}

size_t AuthenticationArguments::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:mifare.av2.args.AuthenticationArguments)
  size_t total_size = 0;

  if (_internal_has_slot()) {
    // required .contact.card_slot.CardSlot slot = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_slot());
  }

  if (_internal_has_key_number()) {
    // required uint32 key_number = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_key_number());
  }

  return total_size;
}
size_t AuthenticationArguments::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mifare.av2.args.AuthenticationArguments)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required .contact.card_slot.CardSlot slot = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_slot());

    // required uint32 key_number = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_key_number());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000cu) {
    // optional uint32 key_version = 3 [default = 0];
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_key_version());
    }

    // optional .mifare.av2.channel.Channel channel = 4 [default = AV2_CHANNEL_0];
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_channel());
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

void AuthenticationArguments::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mifare.av2.args.AuthenticationArguments)
  GOOGLE_DCHECK_NE(&from, this);
  const AuthenticationArguments* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<AuthenticationArguments>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mifare.av2.args.AuthenticationArguments)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mifare.av2.args.AuthenticationArguments)
    MergeFrom(*source);
  }
}

void AuthenticationArguments::MergeFrom(const AuthenticationArguments& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mifare.av2.args.AuthenticationArguments)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      slot_ = from.slot_;
    }
    if (cached_has_bits & 0x00000002u) {
      key_number_ = from.key_number_;
    }
    if (cached_has_bits & 0x00000004u) {
      key_version_ = from.key_version_;
    }
    if (cached_has_bits & 0x00000008u) {
      channel_ = from.channel_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void AuthenticationArguments::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mifare.av2.args.AuthenticationArguments)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AuthenticationArguments::CopyFrom(const AuthenticationArguments& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mifare.av2.args.AuthenticationArguments)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AuthenticationArguments::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  return true;
}

void AuthenticationArguments::InternalSwap(AuthenticationArguments* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(slot_, other->slot_);
  swap(key_number_, other->key_number_);
  swap(key_version_, other->key_version_);
  swap(channel_, other->channel_);
}

::PROTOBUF_NAMESPACE_ID::Metadata AuthenticationArguments::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace args
}  // namespace av2
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mifare::av2::args::AuthenticationArguments* Arena::CreateMaybeMessage< ::mifare::av2::args::AuthenticationArguments >(Arena* arena) {
  return Arena::CreateInternal< ::mifare::av2::args::AuthenticationArguments >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
