// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cipurse/modify_value.proto

#include "cipurse/modify_value.pb.h"

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
namespace modify_value {
class ModifyValueDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ModifyValue> _instance;
} _ModifyValue_default_instance_;
class NewValueDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<NewValue> _instance;
} _NewValue_default_instance_;
}  // namespace modify_value
}  // namespace cipurse
static void InitDefaultsscc_info_ModifyValue_cipurse_2fmodify_5fvalue_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::cipurse::modify_value::_ModifyValue_default_instance_;
    new (ptr) ::cipurse::modify_value::ModifyValue();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::cipurse::modify_value::ModifyValue::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ModifyValue_cipurse_2fmodify_5fvalue_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ModifyValue_cipurse_2fmodify_5fvalue_2eproto}, {}};

static void InitDefaultsscc_info_NewValue_cipurse_2fmodify_5fvalue_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::cipurse::modify_value::_NewValue_default_instance_;
    new (ptr) ::cipurse::modify_value::NewValue();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::cipurse::modify_value::NewValue::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_NewValue_cipurse_2fmodify_5fvalue_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_NewValue_cipurse_2fmodify_5fvalue_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_cipurse_2fmodify_5fvalue_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_cipurse_2fmodify_5fvalue_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_cipurse_2fmodify_5fvalue_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_cipurse_2fmodify_5fvalue_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::ModifyValue, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::ModifyValue, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::ModifyValue, short_file_id_),
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::ModifyValue, operand_),
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::ModifyValue, record_),
  0,
  1,
  2,
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::NewValue, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::NewValue, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::cipurse::modify_value::NewValue, value_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::cipurse::modify_value::ModifyValue)},
  { 11, 17, sizeof(::cipurse::modify_value::NewValue)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::cipurse::modify_value::_ModifyValue_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::cipurse::modify_value::_NewValue_default_instance_),
};

const char descriptor_table_protodef_cipurse_2fmodify_5fvalue_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032cipurse/modify_value.proto\022\024cipurse.mo"
  "dify_value\"H\n\013ModifyValue\022\025\n\rshort_file_"
  "id\030\001 \002(\r\022\017\n\007operand\030\002 \002(\021\022\021\n\006record\030\003 \001("
  "\r:\0011\"\031\n\010NewValue\022\r\n\005value\030\001 \002(\021"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_cipurse_2fmodify_5fvalue_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_cipurse_2fmodify_5fvalue_2eproto_sccs[2] = {
  &scc_info_ModifyValue_cipurse_2fmodify_5fvalue_2eproto.base,
  &scc_info_NewValue_cipurse_2fmodify_5fvalue_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_cipurse_2fmodify_5fvalue_2eproto_once;
static bool descriptor_table_cipurse_2fmodify_5fvalue_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cipurse_2fmodify_5fvalue_2eproto = {
  &descriptor_table_cipurse_2fmodify_5fvalue_2eproto_initialized, descriptor_table_protodef_cipurse_2fmodify_5fvalue_2eproto, "cipurse/modify_value.proto", 151,
  &descriptor_table_cipurse_2fmodify_5fvalue_2eproto_once, descriptor_table_cipurse_2fmodify_5fvalue_2eproto_sccs, descriptor_table_cipurse_2fmodify_5fvalue_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_cipurse_2fmodify_5fvalue_2eproto::offsets,
  file_level_metadata_cipurse_2fmodify_5fvalue_2eproto, 2, file_level_enum_descriptors_cipurse_2fmodify_5fvalue_2eproto, file_level_service_descriptors_cipurse_2fmodify_5fvalue_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_cipurse_2fmodify_5fvalue_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_cipurse_2fmodify_5fvalue_2eproto), true);
namespace cipurse {
namespace modify_value {

// ===================================================================

void ModifyValue::InitAsDefaultInstance() {
}
class ModifyValue::_Internal {
 public:
  using HasBits = decltype(std::declval<ModifyValue>()._has_bits_);
  static void set_has_short_file_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_operand(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_record(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

ModifyValue::ModifyValue()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:cipurse.modify_value.ModifyValue)
}
ModifyValue::ModifyValue(const ModifyValue& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&short_file_id_, &from.short_file_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&record_) -
    reinterpret_cast<char*>(&short_file_id_)) + sizeof(record_));
  // @@protoc_insertion_point(copy_constructor:cipurse.modify_value.ModifyValue)
}

void ModifyValue::SharedCtor() {
  ::memset(&short_file_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&operand_) -
      reinterpret_cast<char*>(&short_file_id_)) + sizeof(operand_));
  record_ = 1u;
}

ModifyValue::~ModifyValue() {
  // @@protoc_insertion_point(destructor:cipurse.modify_value.ModifyValue)
  SharedDtor();
}

void ModifyValue::SharedDtor() {
}

void ModifyValue::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ModifyValue& ModifyValue::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ModifyValue_cipurse_2fmodify_5fvalue_2eproto.base);
  return *internal_default_instance();
}


void ModifyValue::Clear() {
// @@protoc_insertion_point(message_clear_start:cipurse.modify_value.ModifyValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    ::memset(&short_file_id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&operand_) -
        reinterpret_cast<char*>(&short_file_id_)) + sizeof(operand_));
    record_ = 1u;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ModifyValue::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 short_file_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_short_file_id(&has_bits);
          short_file_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required sint32 operand = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_operand(&has_bits);
          operand_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint32 record = 3 [default = 1];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_record(&has_bits);
          record_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ModifyValue::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:cipurse.modify_value.ModifyValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 short_file_id = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_short_file_id(), target);
  }

  // required sint32 operand = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(2, this->_internal_operand(), target);
  }

  // optional uint32 record = 3 [default = 1];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_record(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:cipurse.modify_value.ModifyValue)
  return target;
}

size_t ModifyValue::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:cipurse.modify_value.ModifyValue)
  size_t total_size = 0;

  if (_internal_has_short_file_id()) {
    // required uint32 short_file_id = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_short_file_id());
  }

  if (_internal_has_operand()) {
    // required sint32 operand = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_operand());
  }

  return total_size;
}
size_t ModifyValue::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cipurse.modify_value.ModifyValue)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required uint32 short_file_id = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_short_file_id());

    // required sint32 operand = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_operand());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional uint32 record = 3 [default = 1];
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000004u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_record());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ModifyValue::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:cipurse.modify_value.ModifyValue)
  GOOGLE_DCHECK_NE(&from, this);
  const ModifyValue* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ModifyValue>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:cipurse.modify_value.ModifyValue)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:cipurse.modify_value.ModifyValue)
    MergeFrom(*source);
  }
}

void ModifyValue::MergeFrom(const ModifyValue& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cipurse.modify_value.ModifyValue)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      short_file_id_ = from.short_file_id_;
    }
    if (cached_has_bits & 0x00000002u) {
      operand_ = from.operand_;
    }
    if (cached_has_bits & 0x00000004u) {
      record_ = from.record_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ModifyValue::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:cipurse.modify_value.ModifyValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ModifyValue::CopyFrom(const ModifyValue& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cipurse.modify_value.ModifyValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModifyValue::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  return true;
}

void ModifyValue::InternalSwap(ModifyValue* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(short_file_id_, other->short_file_id_);
  swap(operand_, other->operand_);
  swap(record_, other->record_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ModifyValue::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void NewValue::InitAsDefaultInstance() {
}
class NewValue::_Internal {
 public:
  using HasBits = decltype(std::declval<NewValue>()._has_bits_);
  static void set_has_value(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

NewValue::NewValue()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:cipurse.modify_value.NewValue)
}
NewValue::NewValue(const NewValue& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  value_ = from.value_;
  // @@protoc_insertion_point(copy_constructor:cipurse.modify_value.NewValue)
}

void NewValue::SharedCtor() {
  value_ = 0;
}

NewValue::~NewValue() {
  // @@protoc_insertion_point(destructor:cipurse.modify_value.NewValue)
  SharedDtor();
}

void NewValue::SharedDtor() {
}

void NewValue::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const NewValue& NewValue::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_NewValue_cipurse_2fmodify_5fvalue_2eproto.base);
  return *internal_default_instance();
}


void NewValue::Clear() {
// @@protoc_insertion_point(message_clear_start:cipurse.modify_value.NewValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  value_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* NewValue::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required sint32 value = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_value(&has_bits);
          value_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* NewValue::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:cipurse.modify_value.NewValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required sint32 value = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(1, this->_internal_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:cipurse.modify_value.NewValue)
  return target;
}

size_t NewValue::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cipurse.modify_value.NewValue)
  size_t total_size = 0;

  // required sint32 value = 1;
  if (_internal_has_value()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_value());
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

void NewValue::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:cipurse.modify_value.NewValue)
  GOOGLE_DCHECK_NE(&from, this);
  const NewValue* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<NewValue>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:cipurse.modify_value.NewValue)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:cipurse.modify_value.NewValue)
    MergeFrom(*source);
  }
}

void NewValue::MergeFrom(const NewValue& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cipurse.modify_value.NewValue)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_value()) {
    _internal_set_value(from._internal_value());
  }
}

void NewValue::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:cipurse.modify_value.NewValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NewValue::CopyFrom(const NewValue& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cipurse.modify_value.NewValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NewValue::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void NewValue::InternalSwap(NewValue* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(value_, other->value_);
}

::PROTOBUF_NAMESPACE_ID::Metadata NewValue::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace modify_value
}  // namespace cipurse
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::cipurse::modify_value::ModifyValue* Arena::CreateMaybeMessage< ::cipurse::modify_value::ModifyValue >(Arena* arena) {
  return Arena::CreateInternal< ::cipurse::modify_value::ModifyValue >(arena);
}
template<> PROTOBUF_NOINLINE ::cipurse::modify_value::NewValue* Arena::CreateMaybeMessage< ::cipurse::modify_value::NewValue >(Arena* arena) {
  return Arena::CreateInternal< ::cipurse::modify_value::NewValue >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>