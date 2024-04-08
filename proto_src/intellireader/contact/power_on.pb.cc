// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: contact/power_on.proto

#include "contact/power_on.pb.h"

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
namespace contact {
namespace power_on {
class PowerOnCardDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PowerOnCard> _instance;
} _PowerOnCard_default_instance_;
class ContactCardDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ContactCard> _instance;
} _ContactCard_default_instance_;
}  // namespace power_on
}  // namespace contact
static void InitDefaultsscc_info_ContactCard_contact_2fpower_5fon_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::contact::power_on::_ContactCard_default_instance_;
    new (ptr) ::contact::power_on::ContactCard();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::contact::power_on::ContactCard::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ContactCard_contact_2fpower_5fon_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ContactCard_contact_2fpower_5fon_2eproto}, {}};

static void InitDefaultsscc_info_PowerOnCard_contact_2fpower_5fon_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::contact::power_on::_PowerOnCard_default_instance_;
    new (ptr) ::contact::power_on::PowerOnCard();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::contact::power_on::PowerOnCard::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PowerOnCard_contact_2fpower_5fon_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_PowerOnCard_contact_2fpower_5fon_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_contact_2fpower_5fon_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_contact_2fpower_5fon_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_contact_2fpower_5fon_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_contact_2fpower_5fon_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::contact::power_on::PowerOnCard, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::contact::power_on::PowerOnCard, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::contact::power_on::PowerOnCard, slot_),
  0,
  PROTOBUF_FIELD_OFFSET(::contact::power_on::ContactCard, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::contact::power_on::ContactCard, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::contact::power_on::ContactCard, historical_bytes_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::contact::power_on::PowerOnCard)},
  { 7, 13, sizeof(::contact::power_on::ContactCard)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::contact::power_on::_PowerOnCard_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::contact::power_on::_ContactCard_default_instance_),
};

const char descriptor_table_protodef_contact_2fpower_5fon_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026contact/power_on.proto\022\020contact.power_"
  "on\032\027contact/card_slot.proto\"8\n\013PowerOnCa"
  "rd\022)\n\004slot\030\001 \002(\0162\033.contact.card_slot.Car"
  "dSlot\"\'\n\013ContactCard\022\030\n\020historical_bytes"
  "\030\001 \002(\014"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_contact_2fpower_5fon_2eproto_deps[1] = {
  &::descriptor_table_contact_2fcard_5fslot_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_contact_2fpower_5fon_2eproto_sccs[2] = {
  &scc_info_ContactCard_contact_2fpower_5fon_2eproto.base,
  &scc_info_PowerOnCard_contact_2fpower_5fon_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_contact_2fpower_5fon_2eproto_once;
static bool descriptor_table_contact_2fpower_5fon_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_contact_2fpower_5fon_2eproto = {
  &descriptor_table_contact_2fpower_5fon_2eproto_initialized, descriptor_table_protodef_contact_2fpower_5fon_2eproto, "contact/power_on.proto", 166,
  &descriptor_table_contact_2fpower_5fon_2eproto_once, descriptor_table_contact_2fpower_5fon_2eproto_sccs, descriptor_table_contact_2fpower_5fon_2eproto_deps, 2, 1,
  schemas, file_default_instances, TableStruct_contact_2fpower_5fon_2eproto::offsets,
  file_level_metadata_contact_2fpower_5fon_2eproto, 2, file_level_enum_descriptors_contact_2fpower_5fon_2eproto, file_level_service_descriptors_contact_2fpower_5fon_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_contact_2fpower_5fon_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_contact_2fpower_5fon_2eproto), true);
namespace contact {
namespace power_on {

// ===================================================================

void PowerOnCard::InitAsDefaultInstance() {
}
class PowerOnCard::_Internal {
 public:
  using HasBits = decltype(std::declval<PowerOnCard>()._has_bits_);
  static void set_has_slot(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

PowerOnCard::PowerOnCard()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:contact.power_on.PowerOnCard)
}
PowerOnCard::PowerOnCard(const PowerOnCard& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  slot_ = from.slot_;
  // @@protoc_insertion_point(copy_constructor:contact.power_on.PowerOnCard)
}

void PowerOnCard::SharedCtor() {
  slot_ = 0;
}

PowerOnCard::~PowerOnCard() {
  // @@protoc_insertion_point(destructor:contact.power_on.PowerOnCard)
  SharedDtor();
}

void PowerOnCard::SharedDtor() {
}

void PowerOnCard::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PowerOnCard& PowerOnCard::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PowerOnCard_contact_2fpower_5fon_2eproto.base);
  return *internal_default_instance();
}


void PowerOnCard::Clear() {
// @@protoc_insertion_point(message_clear_start:contact.power_on.PowerOnCard)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  slot_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* PowerOnCard::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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

::PROTOBUF_NAMESPACE_ID::uint8* PowerOnCard::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:contact.power_on.PowerOnCard)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .contact.card_slot.CardSlot slot = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_slot(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:contact.power_on.PowerOnCard)
  return target;
}

size_t PowerOnCard::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:contact.power_on.PowerOnCard)
  size_t total_size = 0;

  // required .contact.card_slot.CardSlot slot = 1;
  if (_internal_has_slot()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_slot());
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

void PowerOnCard::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:contact.power_on.PowerOnCard)
  GOOGLE_DCHECK_NE(&from, this);
  const PowerOnCard* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PowerOnCard>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:contact.power_on.PowerOnCard)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:contact.power_on.PowerOnCard)
    MergeFrom(*source);
  }
}

void PowerOnCard::MergeFrom(const PowerOnCard& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:contact.power_on.PowerOnCard)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_slot()) {
    _internal_set_slot(from._internal_slot());
  }
}

void PowerOnCard::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:contact.power_on.PowerOnCard)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PowerOnCard::CopyFrom(const PowerOnCard& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:contact.power_on.PowerOnCard)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PowerOnCard::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void PowerOnCard::InternalSwap(PowerOnCard* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(slot_, other->slot_);
}

::PROTOBUF_NAMESPACE_ID::Metadata PowerOnCard::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ContactCard::InitAsDefaultInstance() {
}
class ContactCard::_Internal {
 public:
  using HasBits = decltype(std::declval<ContactCard>()._has_bits_);
  static void set_has_historical_bytes(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

ContactCard::ContactCard()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:contact.power_on.ContactCard)
}
ContactCard::ContactCard(const ContactCard& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  historical_bytes_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_historical_bytes()) {
    historical_bytes_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.historical_bytes_);
  }
  // @@protoc_insertion_point(copy_constructor:contact.power_on.ContactCard)
}

void ContactCard::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ContactCard_contact_2fpower_5fon_2eproto.base);
  historical_bytes_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ContactCard::~ContactCard() {
  // @@protoc_insertion_point(destructor:contact.power_on.ContactCard)
  SharedDtor();
}

void ContactCard::SharedDtor() {
  historical_bytes_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ContactCard::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ContactCard& ContactCard::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ContactCard_contact_2fpower_5fon_2eproto.base);
  return *internal_default_instance();
}


void ContactCard::Clear() {
// @@protoc_insertion_point(message_clear_start:contact.power_on.ContactCard)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    historical_bytes_.ClearNonDefaultToEmptyNoArena();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ContactCard::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required bytes historical_bytes = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_historical_bytes();
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

::PROTOBUF_NAMESPACE_ID::uint8* ContactCard::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:contact.power_on.ContactCard)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required bytes historical_bytes = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_historical_bytes(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:contact.power_on.ContactCard)
  return target;
}

size_t ContactCard::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:contact.power_on.ContactCard)
  size_t total_size = 0;

  // required bytes historical_bytes = 1;
  if (_internal_has_historical_bytes()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_historical_bytes());
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

void ContactCard::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:contact.power_on.ContactCard)
  GOOGLE_DCHECK_NE(&from, this);
  const ContactCard* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ContactCard>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:contact.power_on.ContactCard)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:contact.power_on.ContactCard)
    MergeFrom(*source);
  }
}

void ContactCard::MergeFrom(const ContactCard& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:contact.power_on.ContactCard)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_historical_bytes()) {
    _has_bits_[0] |= 0x00000001u;
    historical_bytes_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.historical_bytes_);
  }
}

void ContactCard::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:contact.power_on.ContactCard)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ContactCard::CopyFrom(const ContactCard& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:contact.power_on.ContactCard)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ContactCard::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void ContactCard::InternalSwap(ContactCard* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  historical_bytes_.Swap(&other->historical_bytes_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata ContactCard::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace power_on
}  // namespace contact
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::contact::power_on::PowerOnCard* Arena::CreateMaybeMessage< ::contact::power_on::PowerOnCard >(Arena* arena) {
  return Arena::CreateInternal< ::contact::power_on::PowerOnCard >(arena);
}
template<> PROTOBUF_NOINLINE ::contact::power_on::ContactCard* Arena::CreateMaybeMessage< ::contact::power_on::ContactCard >(Arena* arena) {
  return Arena::CreateInternal< ::contact::power_on::ContactCard >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>