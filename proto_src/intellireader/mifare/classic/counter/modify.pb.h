// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/classic/counter/modify.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fcounter_2fmodify_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fcounter_2fmodify_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_mifare_2fclassic_2fcounter_2fmodify_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mifare_2fclassic_2fcounter_2fmodify_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fclassic_2fcounter_2fmodify_2eproto;
namespace mifare {
namespace classic {
namespace counter {
namespace modify {
class ModifyCounter;
class ModifyCounterDefaultTypeInternal;
extern ModifyCounterDefaultTypeInternal _ModifyCounter_default_instance_;
}  // namespace modify
}  // namespace counter
}  // namespace classic
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> ::mifare::classic::counter::modify::ModifyCounter* Arena::CreateMaybeMessage<::mifare::classic::counter::modify::ModifyCounter>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mifare {
namespace classic {
namespace counter {
namespace modify {

// ===================================================================

class ModifyCounter :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.classic.counter.modify.ModifyCounter) */ {
 public:
  ModifyCounter();
  virtual ~ModifyCounter();

  ModifyCounter(const ModifyCounter& from);
  ModifyCounter(ModifyCounter&& from) noexcept
    : ModifyCounter() {
    *this = ::std::move(from);
  }

  inline ModifyCounter& operator=(const ModifyCounter& from) {
    CopyFrom(from);
    return *this;
  }
  inline ModifyCounter& operator=(ModifyCounter&& from) noexcept {
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
  static const ModifyCounter& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ModifyCounter* internal_default_instance() {
    return reinterpret_cast<const ModifyCounter*>(
               &_ModifyCounter_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ModifyCounter& a, ModifyCounter& b) {
    a.Swap(&b);
  }
  inline void Swap(ModifyCounter* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ModifyCounter* New() const final {
    return CreateMaybeMessage<ModifyCounter>(nullptr);
  }

  ModifyCounter* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ModifyCounter>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ModifyCounter& from);
  void MergeFrom(const ModifyCounter& from);
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
  void InternalSwap(ModifyCounter* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.classic.counter.modify.ModifyCounter";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fclassic_2fcounter_2fmodify_2eproto);
    return ::descriptor_table_mifare_2fclassic_2fcounter_2fmodify_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSrcBlockFieldNumber = 1,
    kOperandFieldNumber = 2,
    kDstBlockFieldNumber = 3,
  };
  // required uint32 src_block = 1;
  bool has_src_block() const;
  private:
  bool _internal_has_src_block() const;
  public:
  void clear_src_block();
  ::PROTOBUF_NAMESPACE_ID::uint32 src_block() const;
  void set_src_block(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_src_block() const;
  void _internal_set_src_block(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required int32 operand = 2;
  bool has_operand() const;
  private:
  bool _internal_has_operand() const;
  public:
  void clear_operand();
  ::PROTOBUF_NAMESPACE_ID::int32 operand() const;
  void set_operand(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_operand() const;
  void _internal_set_operand(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional uint32 dst_block = 3;
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

  // @@protoc_insertion_point(class_scope:mifare.classic.counter.modify.ModifyCounter)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 src_block_;
  ::PROTOBUF_NAMESPACE_ID::int32 operand_;
  ::PROTOBUF_NAMESPACE_ID::uint32 dst_block_;
  friend struct ::TableStruct_mifare_2fclassic_2fcounter_2fmodify_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ModifyCounter

// required uint32 src_block = 1;
inline bool ModifyCounter::_internal_has_src_block() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ModifyCounter::has_src_block() const {
  return _internal_has_src_block();
}
inline void ModifyCounter::clear_src_block() {
  src_block_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ModifyCounter::_internal_src_block() const {
  return src_block_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ModifyCounter::src_block() const {
  // @@protoc_insertion_point(field_get:mifare.classic.counter.modify.ModifyCounter.src_block)
  return _internal_src_block();
}
inline void ModifyCounter::_internal_set_src_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000001u;
  src_block_ = value;
}
inline void ModifyCounter::set_src_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_src_block(value);
  // @@protoc_insertion_point(field_set:mifare.classic.counter.modify.ModifyCounter.src_block)
}

// required int32 operand = 2;
inline bool ModifyCounter::_internal_has_operand() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ModifyCounter::has_operand() const {
  return _internal_has_operand();
}
inline void ModifyCounter::clear_operand() {
  operand_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ModifyCounter::_internal_operand() const {
  return operand_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ModifyCounter::operand() const {
  // @@protoc_insertion_point(field_get:mifare.classic.counter.modify.ModifyCounter.operand)
  return _internal_operand();
}
inline void ModifyCounter::_internal_set_operand(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  operand_ = value;
}
inline void ModifyCounter::set_operand(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_operand(value);
  // @@protoc_insertion_point(field_set:mifare.classic.counter.modify.ModifyCounter.operand)
}

// optional uint32 dst_block = 3;
inline bool ModifyCounter::_internal_has_dst_block() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ModifyCounter::has_dst_block() const {
  return _internal_has_dst_block();
}
inline void ModifyCounter::clear_dst_block() {
  dst_block_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ModifyCounter::_internal_dst_block() const {
  return dst_block_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ModifyCounter::dst_block() const {
  // @@protoc_insertion_point(field_get:mifare.classic.counter.modify.ModifyCounter.dst_block)
  return _internal_dst_block();
}
inline void ModifyCounter::_internal_set_dst_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  dst_block_ = value;
}
inline void ModifyCounter::set_dst_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_dst_block(value);
  // @@protoc_insertion_point(field_set:mifare.classic.counter.modify.ModifyCounter.dst_block)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace modify
}  // namespace counter
}  // namespace classic
}  // namespace mifare

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fcounter_2fmodify_2eproto
