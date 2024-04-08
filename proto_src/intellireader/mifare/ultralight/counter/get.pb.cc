// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/ultralight/counter/get.proto

#include "mifare/ultralight/counter/get.pb.h"

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
namespace ultralight {
namespace counter {
namespace get {
class GetCounterDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GetCounter> _instance;
} _GetCounter_default_instance_;
class CounterValueDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CounterValue> _instance;
} _CounterValue_default_instance_;
}  // namespace get
}  // namespace counter
}  // namespace ultralight
}  // namespace mifare
static void InitDefaultsscc_info_CounterValue_mifare_2fultralight_2fcounter_2fget_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mifare::ultralight::counter::get::_CounterValue_default_instance_;
    new (ptr) ::mifare::ultralight::counter::get::CounterValue();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mifare::ultralight::counter::get::CounterValue::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CounterValue_mifare_2fultralight_2fcounter_2fget_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_CounterValue_mifare_2fultralight_2fcounter_2fget_2eproto}, {}};

static void InitDefaultsscc_info_GetCounter_mifare_2fultralight_2fcounter_2fget_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mifare::ultralight::counter::get::_GetCounter_default_instance_;
    new (ptr) ::mifare::ultralight::counter::get::GetCounter();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mifare::ultralight::counter::get::GetCounter::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GetCounter_mifare_2fultralight_2fcounter_2fget_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_GetCounter_mifare_2fultralight_2fcounter_2fget_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_mifare_2fultralight_2fcounter_2fget_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_mifare_2fultralight_2fcounter_2fget_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_mifare_2fultralight_2fcounter_2fget_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_mifare_2fultralight_2fcounter_2fget_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::mifare::ultralight::counter::get::GetCounter, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::mifare::ultralight::counter::get::GetCounter, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mifare::ultralight::counter::get::GetCounter, counter_number_),
  0,
  PROTOBUF_FIELD_OFFSET(::mifare::ultralight::counter::get::CounterValue, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::mifare::ultralight::counter::get::CounterValue, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mifare::ultralight::counter::get::CounterValue, value_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::mifare::ultralight::counter::get::GetCounter)},
  { 7, 13, sizeof(::mifare::ultralight::counter::get::CounterValue)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mifare::ultralight::counter::get::_GetCounter_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mifare::ultralight::counter::get::_CounterValue_default_instance_),
};

const char descriptor_table_protodef_mifare_2fultralight_2fcounter_2fget_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n#mifare/ultralight/counter/get.proto\022\035m"
  "ifare.ultralight.counter.get\032&mifare/ult"
  "ralight/counter/number.proto\"U\n\nGetCount"
  "er\022G\n\016counter_number\030\001 \002(\0162/.mifare.ultr"
  "alight.counter.number.CounterNumber\"\035\n\014C"
  "ounterValue\022\r\n\005value\030\001 \002(\r"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_deps[1] = {
  &::descriptor_table_mifare_2fultralight_2fcounter_2fnumber_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_sccs[2] = {
  &scc_info_CounterValue_mifare_2fultralight_2fcounter_2fget_2eproto.base,
  &scc_info_GetCounter_mifare_2fultralight_2fcounter_2fget_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_once;
static bool descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto = {
  &descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_initialized, descriptor_table_protodef_mifare_2fultralight_2fcounter_2fget_2eproto, "mifare/ultralight/counter/get.proto", 226,
  &descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_once, descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_sccs, descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto_deps, 2, 1,
  schemas, file_default_instances, TableStruct_mifare_2fultralight_2fcounter_2fget_2eproto::offsets,
  file_level_metadata_mifare_2fultralight_2fcounter_2fget_2eproto, 2, file_level_enum_descriptors_mifare_2fultralight_2fcounter_2fget_2eproto, file_level_service_descriptors_mifare_2fultralight_2fcounter_2fget_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_mifare_2fultralight_2fcounter_2fget_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_mifare_2fultralight_2fcounter_2fget_2eproto), true);
namespace mifare {
namespace ultralight {
namespace counter {
namespace get {

// ===================================================================

void GetCounter::InitAsDefaultInstance() {
}
class GetCounter::_Internal {
 public:
  using HasBits = decltype(std::declval<GetCounter>()._has_bits_);
  static void set_has_counter_number(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

GetCounter::GetCounter()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mifare.ultralight.counter.get.GetCounter)
}
GetCounter::GetCounter(const GetCounter& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  counter_number_ = from.counter_number_;
  // @@protoc_insertion_point(copy_constructor:mifare.ultralight.counter.get.GetCounter)
}

void GetCounter::SharedCtor() {
  counter_number_ = 0;
}

GetCounter::~GetCounter() {
  // @@protoc_insertion_point(destructor:mifare.ultralight.counter.get.GetCounter)
  SharedDtor();
}

void GetCounter::SharedDtor() {
}

void GetCounter::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GetCounter& GetCounter::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GetCounter_mifare_2fultralight_2fcounter_2fget_2eproto.base);
  return *internal_default_instance();
}


void GetCounter::Clear() {
// @@protoc_insertion_point(message_clear_start:mifare.ultralight.counter.get.GetCounter)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  counter_number_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* GetCounter::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required .mifare.ultralight.counter.number.CounterNumber counter_number = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::mifare::ultralight::counter::number::CounterNumber_IsValid(val))) {
            _internal_set_counter_number(static_cast<::mifare::ultralight::counter::number::CounterNumber>(val));
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

::PROTOBUF_NAMESPACE_ID::uint8* GetCounter::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mifare.ultralight.counter.get.GetCounter)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .mifare.ultralight.counter.number.CounterNumber counter_number = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_counter_number(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mifare.ultralight.counter.get.GetCounter)
  return target;
}

size_t GetCounter::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mifare.ultralight.counter.get.GetCounter)
  size_t total_size = 0;

  // required .mifare.ultralight.counter.number.CounterNumber counter_number = 1;
  if (_internal_has_counter_number()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_counter_number());
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

void GetCounter::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mifare.ultralight.counter.get.GetCounter)
  GOOGLE_DCHECK_NE(&from, this);
  const GetCounter* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GetCounter>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mifare.ultralight.counter.get.GetCounter)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mifare.ultralight.counter.get.GetCounter)
    MergeFrom(*source);
  }
}

void GetCounter::MergeFrom(const GetCounter& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mifare.ultralight.counter.get.GetCounter)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_counter_number()) {
    _internal_set_counter_number(from._internal_counter_number());
  }
}

void GetCounter::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mifare.ultralight.counter.get.GetCounter)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetCounter::CopyFrom(const GetCounter& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mifare.ultralight.counter.get.GetCounter)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetCounter::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void GetCounter::InternalSwap(GetCounter* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(counter_number_, other->counter_number_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetCounter::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void CounterValue::InitAsDefaultInstance() {
}
class CounterValue::_Internal {
 public:
  using HasBits = decltype(std::declval<CounterValue>()._has_bits_);
  static void set_has_value(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CounterValue::CounterValue()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mifare.ultralight.counter.get.CounterValue)
}
CounterValue::CounterValue(const CounterValue& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  value_ = from.value_;
  // @@protoc_insertion_point(copy_constructor:mifare.ultralight.counter.get.CounterValue)
}

void CounterValue::SharedCtor() {
  value_ = 0u;
}

CounterValue::~CounterValue() {
  // @@protoc_insertion_point(destructor:mifare.ultralight.counter.get.CounterValue)
  SharedDtor();
}

void CounterValue::SharedDtor() {
}

void CounterValue::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CounterValue& CounterValue::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CounterValue_mifare_2fultralight_2fcounter_2fget_2eproto.base);
  return *internal_default_instance();
}


void CounterValue::Clear() {
// @@protoc_insertion_point(message_clear_start:mifare.ultralight.counter.get.CounterValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  value_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* CounterValue::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 value = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_value(&has_bits);
          value_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* CounterValue::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mifare.ultralight.counter.get.CounterValue)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 value = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mifare.ultralight.counter.get.CounterValue)
  return target;
}

size_t CounterValue::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mifare.ultralight.counter.get.CounterValue)
  size_t total_size = 0;

  // required uint32 value = 1;
  if (_internal_has_value()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
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

void CounterValue::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mifare.ultralight.counter.get.CounterValue)
  GOOGLE_DCHECK_NE(&from, this);
  const CounterValue* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CounterValue>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mifare.ultralight.counter.get.CounterValue)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mifare.ultralight.counter.get.CounterValue)
    MergeFrom(*source);
  }
}

void CounterValue::MergeFrom(const CounterValue& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mifare.ultralight.counter.get.CounterValue)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_value()) {
    _internal_set_value(from._internal_value());
  }
}

void CounterValue::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mifare.ultralight.counter.get.CounterValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CounterValue::CopyFrom(const CounterValue& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mifare.ultralight.counter.get.CounterValue)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CounterValue::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void CounterValue::InternalSwap(CounterValue* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(value_, other->value_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CounterValue::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace get
}  // namespace counter
}  // namespace ultralight
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mifare::ultralight::counter::get::GetCounter* Arena::CreateMaybeMessage< ::mifare::ultralight::counter::get::GetCounter >(Arena* arena) {
  return Arena::CreateInternal< ::mifare::ultralight::counter::get::GetCounter >(arena);
}
template<> PROTOBUF_NOINLINE ::mifare::ultralight::counter::get::CounterValue* Arena::CreateMaybeMessage< ::mifare::ultralight::counter::get::CounterValue >(Arena* arena) {
  return Arena::CreateInternal< ::mifare::ultralight::counter::get::CounterValue >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>