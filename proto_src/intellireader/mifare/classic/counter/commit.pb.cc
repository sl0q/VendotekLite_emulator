// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/classic/counter/commit.proto

#include "mifare/classic/counter/commit.pb.h"

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
namespace classic {
namespace counter {
namespace commit {
class CommitCounterDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CommitCounter> _instance;
} _CommitCounter_default_instance_;
}  // namespace commit
}  // namespace counter
}  // namespace classic
}  // namespace mifare
static void InitDefaultsscc_info_CommitCounter_mifare_2fclassic_2fcounter_2fcommit_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mifare::classic::counter::commit::_CommitCounter_default_instance_;
    new (ptr) ::mifare::classic::counter::commit::CommitCounter();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mifare::classic::counter::commit::CommitCounter::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CommitCounter_mifare_2fclassic_2fcounter_2fcommit_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_CommitCounter_mifare_2fclassic_2fcounter_2fcommit_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_mifare_2fclassic_2fcounter_2fcommit_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_mifare_2fclassic_2fcounter_2fcommit_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_mifare_2fclassic_2fcounter_2fcommit_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_mifare_2fclassic_2fcounter_2fcommit_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::mifare::classic::counter::commit::CommitCounter, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::mifare::classic::counter::commit::CommitCounter, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mifare::classic::counter::commit::CommitCounter, dst_block_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::mifare::classic::counter::commit::CommitCounter)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mifare::classic::counter::commit::_CommitCounter_default_instance_),
};

const char descriptor_table_protodef_mifare_2fclassic_2fcounter_2fcommit_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n#mifare/classic/counter/commit.proto\022\035m"
  "ifare.classic.counter.commit\"\"\n\rCommitCo"
  "unter\022\021\n\tdst_block\030\001 \002(\r"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_sccs[1] = {
  &scc_info_CommitCounter_mifare_2fclassic_2fcounter_2fcommit_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_once;
static bool descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto = {
  &descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_initialized, descriptor_table_protodef_mifare_2fclassic_2fcounter_2fcommit_2eproto, "mifare/classic/counter/commit.proto", 104,
  &descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_once, descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_sccs, descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_mifare_2fclassic_2fcounter_2fcommit_2eproto::offsets,
  file_level_metadata_mifare_2fclassic_2fcounter_2fcommit_2eproto, 1, file_level_enum_descriptors_mifare_2fclassic_2fcounter_2fcommit_2eproto, file_level_service_descriptors_mifare_2fclassic_2fcounter_2fcommit_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_mifare_2fclassic_2fcounter_2fcommit_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_mifare_2fclassic_2fcounter_2fcommit_2eproto), true);
namespace mifare {
namespace classic {
namespace counter {
namespace commit {

// ===================================================================

void CommitCounter::InitAsDefaultInstance() {
}
class CommitCounter::_Internal {
 public:
  using HasBits = decltype(std::declval<CommitCounter>()._has_bits_);
  static void set_has_dst_block(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CommitCounter::CommitCounter()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mifare.classic.counter.commit.CommitCounter)
}
CommitCounter::CommitCounter(const CommitCounter& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  dst_block_ = from.dst_block_;
  // @@protoc_insertion_point(copy_constructor:mifare.classic.counter.commit.CommitCounter)
}

void CommitCounter::SharedCtor() {
  dst_block_ = 0u;
}

CommitCounter::~CommitCounter() {
  // @@protoc_insertion_point(destructor:mifare.classic.counter.commit.CommitCounter)
  SharedDtor();
}

void CommitCounter::SharedDtor() {
}

void CommitCounter::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CommitCounter& CommitCounter::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CommitCounter_mifare_2fclassic_2fcounter_2fcommit_2eproto.base);
  return *internal_default_instance();
}


void CommitCounter::Clear() {
// @@protoc_insertion_point(message_clear_start:mifare.classic.counter.commit.CommitCounter)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  dst_block_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* CommitCounter::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 dst_block = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_dst_block(&has_bits);
          dst_block_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* CommitCounter::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mifare.classic.counter.commit.CommitCounter)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 dst_block = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_dst_block(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mifare.classic.counter.commit.CommitCounter)
  return target;
}

size_t CommitCounter::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mifare.classic.counter.commit.CommitCounter)
  size_t total_size = 0;

  // required uint32 dst_block = 1;
  if (_internal_has_dst_block()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_dst_block());
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

void CommitCounter::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mifare.classic.counter.commit.CommitCounter)
  GOOGLE_DCHECK_NE(&from, this);
  const CommitCounter* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CommitCounter>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mifare.classic.counter.commit.CommitCounter)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mifare.classic.counter.commit.CommitCounter)
    MergeFrom(*source);
  }
}

void CommitCounter::MergeFrom(const CommitCounter& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mifare.classic.counter.commit.CommitCounter)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_dst_block()) {
    _internal_set_dst_block(from._internal_dst_block());
  }
}

void CommitCounter::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mifare.classic.counter.commit.CommitCounter)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CommitCounter::CopyFrom(const CommitCounter& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mifare.classic.counter.commit.CommitCounter)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CommitCounter::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void CommitCounter::InternalSwap(CommitCounter* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(dst_block_, other->dst_block_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CommitCounter::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace commit
}  // namespace counter
}  // namespace classic
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mifare::classic::counter::commit::CommitCounter* Arena::CreateMaybeMessage< ::mifare::classic::counter::commit::CommitCounter >(Arena* arena) {
  return Arena::CreateInternal< ::mifare::classic::counter::commit::CommitCounter >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
