// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: misc/baudrate.proto

#include "misc/baudrate.pb.h"

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
namespace baudrate {
class ChangeBaudrateDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ChangeBaudrate> _instance;
} _ChangeBaudrate_default_instance_;
}  // namespace baudrate
}  // namespace misc
static void InitDefaultsscc_info_ChangeBaudrate_misc_2fbaudrate_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::misc::baudrate::_ChangeBaudrate_default_instance_;
    new (ptr) ::misc::baudrate::ChangeBaudrate();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::misc::baudrate::ChangeBaudrate::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ChangeBaudrate_misc_2fbaudrate_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ChangeBaudrate_misc_2fbaudrate_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_misc_2fbaudrate_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_misc_2fbaudrate_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_misc_2fbaudrate_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_misc_2fbaudrate_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::misc::baudrate::ChangeBaudrate, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::misc::baudrate::ChangeBaudrate, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::misc::baudrate::ChangeBaudrate, baudrate_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::misc::baudrate::ChangeBaudrate)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::misc::baudrate::_ChangeBaudrate_default_instance_),
};

const char descriptor_table_protodef_misc_2fbaudrate_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023misc/baudrate.proto\022\rmisc.baudrate\";\n\016"
  "ChangeBaudrate\022)\n\010baudrate\030\001 \002(\0162\027.misc."
  "baudrate.Baudrate*J\n\010Baudrate\022\016\n\nBPS_115"
  "200\020\000\022\016\n\nBPS_230400\020\001\022\016\n\nBPS_460800\020\002\022\016\n"
  "\nBPS_921600\020\003"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_misc_2fbaudrate_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_misc_2fbaudrate_2eproto_sccs[1] = {
  &scc_info_ChangeBaudrate_misc_2fbaudrate_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_misc_2fbaudrate_2eproto_once;
static bool descriptor_table_misc_2fbaudrate_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_misc_2fbaudrate_2eproto = {
  &descriptor_table_misc_2fbaudrate_2eproto_initialized, descriptor_table_protodef_misc_2fbaudrate_2eproto, "misc/baudrate.proto", 173,
  &descriptor_table_misc_2fbaudrate_2eproto_once, descriptor_table_misc_2fbaudrate_2eproto_sccs, descriptor_table_misc_2fbaudrate_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_misc_2fbaudrate_2eproto::offsets,
  file_level_metadata_misc_2fbaudrate_2eproto, 1, file_level_enum_descriptors_misc_2fbaudrate_2eproto, file_level_service_descriptors_misc_2fbaudrate_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_misc_2fbaudrate_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_misc_2fbaudrate_2eproto), true);
namespace misc {
namespace baudrate {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Baudrate_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_misc_2fbaudrate_2eproto);
  return file_level_enum_descriptors_misc_2fbaudrate_2eproto[0];
}
bool Baudrate_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void ChangeBaudrate::InitAsDefaultInstance() {
}
class ChangeBaudrate::_Internal {
 public:
  using HasBits = decltype(std::declval<ChangeBaudrate>()._has_bits_);
  static void set_has_baudrate(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

ChangeBaudrate::ChangeBaudrate()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:misc.baudrate.ChangeBaudrate)
}
ChangeBaudrate::ChangeBaudrate(const ChangeBaudrate& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  baudrate_ = from.baudrate_;
  // @@protoc_insertion_point(copy_constructor:misc.baudrate.ChangeBaudrate)
}

void ChangeBaudrate::SharedCtor() {
  baudrate_ = 0;
}

ChangeBaudrate::~ChangeBaudrate() {
  // @@protoc_insertion_point(destructor:misc.baudrate.ChangeBaudrate)
  SharedDtor();
}

void ChangeBaudrate::SharedDtor() {
}

void ChangeBaudrate::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ChangeBaudrate& ChangeBaudrate::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ChangeBaudrate_misc_2fbaudrate_2eproto.base);
  return *internal_default_instance();
}


void ChangeBaudrate::Clear() {
// @@protoc_insertion_point(message_clear_start:misc.baudrate.ChangeBaudrate)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  baudrate_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ChangeBaudrate::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required .misc.baudrate.Baudrate baudrate = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::misc::baudrate::Baudrate_IsValid(val))) {
            _internal_set_baudrate(static_cast<::misc::baudrate::Baudrate>(val));
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

::PROTOBUF_NAMESPACE_ID::uint8* ChangeBaudrate::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:misc.baudrate.ChangeBaudrate)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .misc.baudrate.Baudrate baudrate = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_baudrate(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:misc.baudrate.ChangeBaudrate)
  return target;
}

size_t ChangeBaudrate::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:misc.baudrate.ChangeBaudrate)
  size_t total_size = 0;

  // required .misc.baudrate.Baudrate baudrate = 1;
  if (_internal_has_baudrate()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_baudrate());
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

void ChangeBaudrate::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:misc.baudrate.ChangeBaudrate)
  GOOGLE_DCHECK_NE(&from, this);
  const ChangeBaudrate* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ChangeBaudrate>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:misc.baudrate.ChangeBaudrate)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:misc.baudrate.ChangeBaudrate)
    MergeFrom(*source);
  }
}

void ChangeBaudrate::MergeFrom(const ChangeBaudrate& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:misc.baudrate.ChangeBaudrate)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_baudrate()) {
    _internal_set_baudrate(from._internal_baudrate());
  }
}

void ChangeBaudrate::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:misc.baudrate.ChangeBaudrate)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChangeBaudrate::CopyFrom(const ChangeBaudrate& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:misc.baudrate.ChangeBaudrate)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChangeBaudrate::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void ChangeBaudrate::InternalSwap(ChangeBaudrate* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(baudrate_, other->baudrate_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ChangeBaudrate::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace baudrate
}  // namespace misc
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::misc::baudrate::ChangeBaudrate* Arena::CreateMaybeMessage< ::misc::baudrate::ChangeBaudrate >(Arena* arena) {
  return Arena::CreateInternal< ::misc::baudrate::ChangeBaudrate >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
