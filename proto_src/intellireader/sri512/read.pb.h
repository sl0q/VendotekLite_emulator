// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sri512/read.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_sri512_2fread_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_sri512_2fread_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_sri512_2fread_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_sri512_2fread_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_sri512_2fread_2eproto;
namespace stmcard {
namespace sri512 {
namespace read {
class Blocks;
class BlocksDefaultTypeInternal;
extern BlocksDefaultTypeInternal _Blocks_default_instance_;
class ReadBlocks;
class ReadBlocksDefaultTypeInternal;
extern ReadBlocksDefaultTypeInternal _ReadBlocks_default_instance_;
}  // namespace read
}  // namespace sri512
}  // namespace stmcard
PROTOBUF_NAMESPACE_OPEN
template<> ::stmcard::sri512::read::Blocks* Arena::CreateMaybeMessage<::stmcard::sri512::read::Blocks>(Arena*);
template<> ::stmcard::sri512::read::ReadBlocks* Arena::CreateMaybeMessage<::stmcard::sri512::read::ReadBlocks>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace stmcard {
namespace sri512 {
namespace read {

// ===================================================================

class ReadBlocks :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:stmcard.sri512.read.ReadBlocks) */ {
 public:
  ReadBlocks();
  virtual ~ReadBlocks();

  ReadBlocks(const ReadBlocks& from);
  ReadBlocks(ReadBlocks&& from) noexcept
    : ReadBlocks() {
    *this = ::std::move(from);
  }

  inline ReadBlocks& operator=(const ReadBlocks& from) {
    CopyFrom(from);
    return *this;
  }
  inline ReadBlocks& operator=(ReadBlocks&& from) noexcept {
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
  static const ReadBlocks& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ReadBlocks* internal_default_instance() {
    return reinterpret_cast<const ReadBlocks*>(
               &_ReadBlocks_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ReadBlocks& a, ReadBlocks& b) {
    a.Swap(&b);
  }
  inline void Swap(ReadBlocks* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ReadBlocks* New() const final {
    return CreateMaybeMessage<ReadBlocks>(nullptr);
  }

  ReadBlocks* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ReadBlocks>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ReadBlocks& from);
  void MergeFrom(const ReadBlocks& from);
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
  void InternalSwap(ReadBlocks* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "stmcard.sri512.read.ReadBlocks";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_sri512_2fread_2eproto);
    return ::descriptor_table_sri512_2fread_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStartBlockFieldNumber = 1,
    kBlockCountFieldNumber = 2,
  };
  // required uint32 start_block = 1;
  bool has_start_block() const;
  private:
  bool _internal_has_start_block() const;
  public:
  void clear_start_block();
  ::PROTOBUF_NAMESPACE_ID::uint32 start_block() const;
  void set_start_block(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_start_block() const;
  void _internal_set_start_block(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional uint32 block_count = 2 [default = 1];
  bool has_block_count() const;
  private:
  bool _internal_has_block_count() const;
  public:
  void clear_block_count();
  ::PROTOBUF_NAMESPACE_ID::uint32 block_count() const;
  void set_block_count(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_block_count() const;
  void _internal_set_block_count(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:stmcard.sri512.read.ReadBlocks)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 start_block_;
  ::PROTOBUF_NAMESPACE_ID::uint32 block_count_;
  friend struct ::TableStruct_sri512_2fread_2eproto;
};
// -------------------------------------------------------------------

class Blocks :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:stmcard.sri512.read.Blocks) */ {
 public:
  Blocks();
  virtual ~Blocks();

  Blocks(const Blocks& from);
  Blocks(Blocks&& from) noexcept
    : Blocks() {
    *this = ::std::move(from);
  }

  inline Blocks& operator=(const Blocks& from) {
    CopyFrom(from);
    return *this;
  }
  inline Blocks& operator=(Blocks&& from) noexcept {
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
  static const Blocks& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Blocks* internal_default_instance() {
    return reinterpret_cast<const Blocks*>(
               &_Blocks_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Blocks& a, Blocks& b) {
    a.Swap(&b);
  }
  inline void Swap(Blocks* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Blocks* New() const final {
    return CreateMaybeMessage<Blocks>(nullptr);
  }

  Blocks* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Blocks>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Blocks& from);
  void MergeFrom(const Blocks& from);
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
  void InternalSwap(Blocks* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "stmcard.sri512.read.Blocks";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_sri512_2fread_2eproto);
    return ::descriptor_table_sri512_2fread_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDataFieldNumber = 1,
  };
  // required bytes data = 1;
  bool has_data() const;
  private:
  bool _internal_has_data() const;
  public:
  void clear_data();
  const std::string& data() const;
  void set_data(const std::string& value);
  void set_data(std::string&& value);
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  std::string* mutable_data();
  std::string* release_data();
  void set_allocated_data(std::string* data);
  private:
  const std::string& _internal_data() const;
  void _internal_set_data(const std::string& value);
  std::string* _internal_mutable_data();
  public:

  // @@protoc_insertion_point(class_scope:stmcard.sri512.read.Blocks)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
  friend struct ::TableStruct_sri512_2fread_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ReadBlocks

// required uint32 start_block = 1;
inline bool ReadBlocks::_internal_has_start_block() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ReadBlocks::has_start_block() const {
  return _internal_has_start_block();
}
inline void ReadBlocks::clear_start_block() {
  start_block_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBlocks::_internal_start_block() const {
  return start_block_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBlocks::start_block() const {
  // @@protoc_insertion_point(field_get:stmcard.sri512.read.ReadBlocks.start_block)
  return _internal_start_block();
}
inline void ReadBlocks::_internal_set_start_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000001u;
  start_block_ = value;
}
inline void ReadBlocks::set_start_block(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_start_block(value);
  // @@protoc_insertion_point(field_set:stmcard.sri512.read.ReadBlocks.start_block)
}

// optional uint32 block_count = 2 [default = 1];
inline bool ReadBlocks::_internal_has_block_count() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ReadBlocks::has_block_count() const {
  return _internal_has_block_count();
}
inline void ReadBlocks::clear_block_count() {
  block_count_ = 1u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBlocks::_internal_block_count() const {
  return block_count_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBlocks::block_count() const {
  // @@protoc_insertion_point(field_get:stmcard.sri512.read.ReadBlocks.block_count)
  return _internal_block_count();
}
inline void ReadBlocks::_internal_set_block_count(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  block_count_ = value;
}
inline void ReadBlocks::set_block_count(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_block_count(value);
  // @@protoc_insertion_point(field_set:stmcard.sri512.read.ReadBlocks.block_count)
}

// -------------------------------------------------------------------

// Blocks

// required bytes data = 1;
inline bool Blocks::_internal_has_data() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Blocks::has_data() const {
  return _internal_has_data();
}
inline void Blocks::clear_data() {
  data_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Blocks::data() const {
  // @@protoc_insertion_point(field_get:stmcard.sri512.read.Blocks.data)
  return _internal_data();
}
inline void Blocks::set_data(const std::string& value) {
  _internal_set_data(value);
  // @@protoc_insertion_point(field_set:stmcard.sri512.read.Blocks.data)
}
inline std::string* Blocks::mutable_data() {
  // @@protoc_insertion_point(field_mutable:stmcard.sri512.read.Blocks.data)
  return _internal_mutable_data();
}
inline const std::string& Blocks::_internal_data() const {
  return data_.GetNoArena();
}
inline void Blocks::_internal_set_data(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Blocks::set_data(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:stmcard.sri512.read.Blocks.data)
}
inline void Blocks::set_data(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:stmcard.sri512.read.Blocks.data)
}
inline void Blocks::set_data(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:stmcard.sri512.read.Blocks.data)
}
inline std::string* Blocks::_internal_mutable_data() {
  _has_bits_[0] |= 0x00000001u;
  return data_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Blocks::release_data() {
  // @@protoc_insertion_point(field_release:stmcard.sri512.read.Blocks.data)
  if (!_internal_has_data()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return data_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Blocks::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  data_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:stmcard.sri512.read.Blocks.data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace read
}  // namespace sri512
}  // namespace stmcard

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_sri512_2fread_2eproto
