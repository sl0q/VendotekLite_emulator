// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: troika/av3/time.proto

#include "troika/av3/time.pb.h"

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
namespace troika {
namespace av3 {
namespace time {
class TimeDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Time> _instance;
} _Time_default_instance_;
}  // namespace time
}  // namespace av3
}  // namespace troika
static void InitDefaultsscc_info_Time_troika_2fav3_2ftime_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::troika::av3::time::_Time_default_instance_;
    new (ptr) ::troika::av3::time::Time();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::troika::av3::time::Time::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Time_troika_2fav3_2ftime_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Time_troika_2fav3_2ftime_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_troika_2fav3_2ftime_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_troika_2fav3_2ftime_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_troika_2fav3_2ftime_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_troika_2fav3_2ftime_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::troika::av3::time::Time, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::troika::av3::time::Time, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::troika::av3::time::Time, hour_),
  PROTOBUF_FIELD_OFFSET(::troika::av3::time::Time, minute_),
  PROTOBUF_FIELD_OFFSET(::troika::av3::time::Time, second_),
  0,
  1,
  2,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::troika::av3::time::Time)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::troika::av3::time::_Time_default_instance_),
};

const char descriptor_table_protodef_troika_2fav3_2ftime_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025troika/av3/time.proto\022\017troika.av3.time"
  "\"4\n\004Time\022\014\n\004hour\030\001 \002(\r\022\016\n\006minute\030\002 \002(\r\022\016"
  "\n\006second\030\003 \002(\r"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_troika_2fav3_2ftime_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_troika_2fav3_2ftime_2eproto_sccs[1] = {
  &scc_info_Time_troika_2fav3_2ftime_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_troika_2fav3_2ftime_2eproto_once;
static bool descriptor_table_troika_2fav3_2ftime_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_troika_2fav3_2ftime_2eproto = {
  &descriptor_table_troika_2fav3_2ftime_2eproto_initialized, descriptor_table_protodef_troika_2fav3_2ftime_2eproto, "troika/av3/time.proto", 94,
  &descriptor_table_troika_2fav3_2ftime_2eproto_once, descriptor_table_troika_2fav3_2ftime_2eproto_sccs, descriptor_table_troika_2fav3_2ftime_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_troika_2fav3_2ftime_2eproto::offsets,
  file_level_metadata_troika_2fav3_2ftime_2eproto, 1, file_level_enum_descriptors_troika_2fav3_2ftime_2eproto, file_level_service_descriptors_troika_2fav3_2ftime_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_troika_2fav3_2ftime_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_troika_2fav3_2ftime_2eproto), true);
namespace troika {
namespace av3 {
namespace time {

// ===================================================================

void Time::InitAsDefaultInstance() {
}
class Time::_Internal {
 public:
  using HasBits = decltype(std::declval<Time>()._has_bits_);
  static void set_has_hour(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_minute(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_second(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

Time::Time()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:troika.av3.time.Time)
}
Time::Time(const Time& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&hour_, &from.hour_,
    static_cast<size_t>(reinterpret_cast<char*>(&second_) -
    reinterpret_cast<char*>(&hour_)) + sizeof(second_));
  // @@protoc_insertion_point(copy_constructor:troika.av3.time.Time)
}

void Time::SharedCtor() {
  ::memset(&hour_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&second_) -
      reinterpret_cast<char*>(&hour_)) + sizeof(second_));
}

Time::~Time() {
  // @@protoc_insertion_point(destructor:troika.av3.time.Time)
  SharedDtor();
}

void Time::SharedDtor() {
}

void Time::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Time& Time::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Time_troika_2fav3_2ftime_2eproto.base);
  return *internal_default_instance();
}


void Time::Clear() {
// @@protoc_insertion_point(message_clear_start:troika.av3.time.Time)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    ::memset(&hour_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&second_) -
        reinterpret_cast<char*>(&hour_)) + sizeof(second_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Time::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 hour = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_hour(&has_bits);
          hour_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 minute = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_minute(&has_bits);
          minute_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 second = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_second(&has_bits);
          second_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Time::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:troika.av3.time.Time)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 hour = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_hour(), target);
  }

  // required uint32 minute = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_minute(), target);
  }

  // required uint32 second = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_second(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:troika.av3.time.Time)
  return target;
}

size_t Time::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:troika.av3.time.Time)
  size_t total_size = 0;

  if (_internal_has_hour()) {
    // required uint32 hour = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_hour());
  }

  if (_internal_has_minute()) {
    // required uint32 minute = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_minute());
  }

  if (_internal_has_second()) {
    // required uint32 second = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_second());
  }

  return total_size;
}
size_t Time::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:troika.av3.time.Time)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required uint32 hour = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_hour());

    // required uint32 minute = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_minute());

    // required uint32 second = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_second());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
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

void Time::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:troika.av3.time.Time)
  GOOGLE_DCHECK_NE(&from, this);
  const Time* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Time>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:troika.av3.time.Time)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:troika.av3.time.Time)
    MergeFrom(*source);
  }
}

void Time::MergeFrom(const Time& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:troika.av3.time.Time)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      hour_ = from.hour_;
    }
    if (cached_has_bits & 0x00000002u) {
      minute_ = from.minute_;
    }
    if (cached_has_bits & 0x00000004u) {
      second_ = from.second_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Time::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:troika.av3.time.Time)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Time::CopyFrom(const Time& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:troika.av3.time.Time)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Time::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  return true;
}

void Time::InternalSwap(Time* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(hour_, other->hour_);
  swap(minute_, other->minute_);
  swap(second_, other->second_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Time::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace time
}  // namespace av3
}  // namespace troika
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::troika::av3::time::Time* Arena::CreateMaybeMessage< ::troika::av3::time::Time >(Arena* arena) {
  return Arena::CreateInternal< ::troika::av3::time::Time >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>