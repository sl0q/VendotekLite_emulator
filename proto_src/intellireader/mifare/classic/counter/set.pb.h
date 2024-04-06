// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/classic/counter/set.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fcounter_2fset_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fcounter_2fset_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_mifare_2fclassic_2fcounter_2fset_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mifare_2fclassic_2fcounter_2fset_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fclassic_2fcounter_2fset_2eproto;
namespace mifare {
namespace classic {
namespace counter {
namespace set {
class SetCounter;
class SetCounterDefaultTypeInternal;
extern SetCounterDefaultTypeInternal _SetCounter_default_instance_;
}  // namespace set
}  // namespace counter
}  // namespace classic
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> ::mifare::classic::counter::set::SetCounter* Arena::CreateMaybeMessage<::mifare::classic::counter::set::SetCounter>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mifare {
namespace classic {
namespace counter {
namespace set {

// ===================================================================

class SetCounter :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.classic.counter.set.SetCounter) */ {
 public:
  SetCounter();
  virtual ~SetCounter();

  SetCounter(const SetCounter& from);
  SetCounter(SetCounter&& from) noexcept
    : SetCounter() {
    *this = ::std::move(from);
  }

  inline SetCounter& operator=(const SetCounter& from) {
    CopyFrom(from);
    return *this;
  }
  inline SetCounter& operator=(SetCounter&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SetCounter& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SetCounter* internal_default_instance() {
    return reinterpret_cast<const SetCounter*>(
               &_SetCounter_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SetCounter& a, SetCounter& b) {
    a.Swap(&b);
  }
  inline void Swap(SetCounter* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SetCounter* New() const final {
    return CreateMaybeMessage<SetCounter>(nullptr);
  }

  SetCounter* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SetCounter>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SetCounter& from);
  void MergeFrom(const SetCounter& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SetCounter* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.classic.counter.set.SetCounter";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fclassic_2fcounter_2fset_2eproto);
    return ::descriptor_table_mifare_2fclassic_2fcounter_2fset_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDstBlockFieldNumber = 1,
    kValueFieldNumber = 2,
  };
  // required uint32 dst_block = 1;
  bool has_dst_block() const;
  private:
  bool _internal_has_dst_block() const;
  public:
  void clear_dst_block();
  ::PROTOBUF_NAMESPACE_ID::uint32 dst_block() const;
  void set_dst_block(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_dst_block() const;
  void _internal_set_dst_block(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required int32 value = 2;
  bool has_value() const;
  private:
  bool _internal_has_value() const;
  public:
  void clear_value();
  ::PROTOBUF_NAMESPACE_ID::int32 value() const;
  void set_value(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_value() const;
  void _internal_set_value(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:mifare.classic.counter.set.SetCounter)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 dst_block_;
  ::PROTOBUF_NAMESPACE_ID::int32 value_;
  friend struct ::TableStruct_mifare_2fclassic_2fcounter_2fset_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SetCounter

// required uint32 dst_block = 1;
inline bool SetCounter::_internal_has_dst_block() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool SetCounter::has_dst_block() const {
  return _internal_has_dst_block();
}
inline void SetCounter::clear_dst_block() {
  dst_block_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SetCounter::_internal_dst_block() const {
  return dst_block_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SetCounter::dst_block() const {
  // @@protoc_insertion_point(field_get:mifare.classic.counter.set.SetCounter.dst_block)
  return _internal_dst_block();
}
inline void SetCounter::_internal_set_dst_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000001u;
  dst_block_ = value;
}
inline void SetCounter::set_dst_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_dst_block(value);
  // @@protoc_insertion_point(field_set:mifare.classic.counter.set.SetCounter.dst_block)
}

// required int32 value = 2;
inline bool SetCounter::_internal_has_value() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool SetCounter::has_value() const {
  return _internal_has_value();
}
inline void SetCounter::clear_value() {
  value_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SetCounter::_internal_value() const {
  return value_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SetCounter::value() const {
  // @@protoc_insertion_point(field_get:mifare.classic.counter.set.SetCounter.value)
  return _internal_value();
}
inline void SetCounter::_internal_set_value(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  value_ = value;
}
inline void SetCounter::set_value(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:mifare.classic.counter.set.SetCounter.value)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace set
}  // namespace counter
}  // namespace classic
}  // namespace mifare

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fcounter_2fset_2eproto
