// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cipurse/read_binary.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_cipurse_2fread_5fbinary_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_cipurse_2fread_5fbinary_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_cipurse_2fread_5fbinary_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_cipurse_2fread_5fbinary_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cipurse_2fread_5fbinary_2eproto;
namespace cipurse {
namespace read_binary {
class Binary;
class BinaryDefaultTypeInternal;
extern BinaryDefaultTypeInternal _Binary_default_instance_;
class ReadBinary;
class ReadBinaryDefaultTypeInternal;
extern ReadBinaryDefaultTypeInternal _ReadBinary_default_instance_;
}  // namespace read_binary
}  // namespace cipurse
PROTOBUF_NAMESPACE_OPEN
template<> ::cipurse::read_binary::Binary* Arena::CreateMaybeMessage<::cipurse::read_binary::Binary>(Arena*);
template<> ::cipurse::read_binary::ReadBinary* Arena::CreateMaybeMessage<::cipurse::read_binary::ReadBinary>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace cipurse {
namespace read_binary {

// ===================================================================

class ReadBinary :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:cipurse.read_binary.ReadBinary) */ {
 public:
  ReadBinary();
  virtual ~ReadBinary();

  ReadBinary(const ReadBinary& from);
  ReadBinary(ReadBinary&& from) noexcept
    : ReadBinary() {
    *this = ::std::move(from);
  }

  inline ReadBinary& operator=(const ReadBinary& from) {
    CopyFrom(from);
    return *this;
  }
  inline ReadBinary& operator=(ReadBinary&& from) noexcept {
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
  static const ReadBinary& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ReadBinary* internal_default_instance() {
    return reinterpret_cast<const ReadBinary*>(
               &_ReadBinary_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ReadBinary& a, ReadBinary& b) {
    a.Swap(&b);
  }
  inline void Swap(ReadBinary* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ReadBinary* New() const final {
    return CreateMaybeMessage<ReadBinary>(nullptr);
  }

  ReadBinary* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ReadBinary>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ReadBinary& from);
  void MergeFrom(const ReadBinary& from);
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
  void InternalSwap(ReadBinary* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "cipurse.read_binary.ReadBinary";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cipurse_2fread_5fbinary_2eproto);
    return ::descriptor_table_cipurse_2fread_5fbinary_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kShortFileIdFieldNumber = 1,
    kLengthFieldNumber = 2,
    kOffsetFieldNumber = 3,
  };
  // required uint32 short_file_id = 1;
  bool has_short_file_id() const;
  private:
  bool _internal_has_short_file_id() const;
  public:
  void clear_short_file_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 short_file_id() const;
  void set_short_file_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_short_file_id() const;
  void _internal_set_short_file_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 length = 2;
  bool has_length() const;
  private:
  bool _internal_has_length() const;
  public:
  void clear_length();
  ::PROTOBUF_NAMESPACE_ID::uint32 length() const;
  void set_length(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_length() const;
  void _internal_set_length(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional uint32 offset = 3 [default = 0];
  bool has_offset() const;
  private:
  bool _internal_has_offset() const;
  public:
  void clear_offset();
  ::PROTOBUF_NAMESPACE_ID::uint32 offset() const;
  void set_offset(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_offset() const;
  void _internal_set_offset(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:cipurse.read_binary.ReadBinary)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 short_file_id_;
  ::PROTOBUF_NAMESPACE_ID::uint32 length_;
  ::PROTOBUF_NAMESPACE_ID::uint32 offset_;
  friend struct ::TableStruct_cipurse_2fread_5fbinary_2eproto;
};
// -------------------------------------------------------------------

class Binary :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:cipurse.read_binary.Binary) */ {
 public:
  Binary();
  virtual ~Binary();

  Binary(const Binary& from);
  Binary(Binary&& from) noexcept
    : Binary() {
    *this = ::std::move(from);
  }

  inline Binary& operator=(const Binary& from) {
    CopyFrom(from);
    return *this;
  }
  inline Binary& operator=(Binary&& from) noexcept {
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
  static const Binary& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Binary* internal_default_instance() {
    return reinterpret_cast<const Binary*>(
               &_Binary_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Binary& a, Binary& b) {
    a.Swap(&b);
  }
  inline void Swap(Binary* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Binary* New() const final {
    return CreateMaybeMessage<Binary>(nullptr);
  }

  Binary* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Binary>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Binary& from);
  void MergeFrom(const Binary& from);
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
  void InternalSwap(Binary* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "cipurse.read_binary.Binary";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cipurse_2fread_5fbinary_2eproto);
    return ::descriptor_table_cipurse_2fread_5fbinary_2eproto.file_level_metadata[kIndexInFileMessages];
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

  // @@protoc_insertion_point(class_scope:cipurse.read_binary.Binary)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
  friend struct ::TableStruct_cipurse_2fread_5fbinary_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ReadBinary

// required uint32 short_file_id = 1;
inline bool ReadBinary::_internal_has_short_file_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ReadBinary::has_short_file_id() const {
  return _internal_has_short_file_id();
}
inline void ReadBinary::clear_short_file_id() {
  short_file_id_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBinary::_internal_short_file_id() const {
  return short_file_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBinary::short_file_id() const {
  // @@protoc_insertion_point(field_get:cipurse.read_binary.ReadBinary.short_file_id)
  return _internal_short_file_id();
}
inline void ReadBinary::_internal_set_short_file_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000001u;
  short_file_id_ = value;
}
inline void ReadBinary::set_short_file_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_short_file_id(value);
  // @@protoc_insertion_point(field_set:cipurse.read_binary.ReadBinary.short_file_id)
}

// required uint32 length = 2;
inline bool ReadBinary::_internal_has_length() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ReadBinary::has_length() const {
  return _internal_has_length();
}
inline void ReadBinary::clear_length() {
  length_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBinary::_internal_length() const {
  return length_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBinary::length() const {
  // @@protoc_insertion_point(field_get:cipurse.read_binary.ReadBinary.length)
  return _internal_length();
}
inline void ReadBinary::_internal_set_length(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  length_ = value;
}
inline void ReadBinary::set_length(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_length(value);
  // @@protoc_insertion_point(field_set:cipurse.read_binary.ReadBinary.length)
}

// optional uint32 offset = 3 [default = 0];
inline bool ReadBinary::_internal_has_offset() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ReadBinary::has_offset() const {
  return _internal_has_offset();
}
inline void ReadBinary::clear_offset() {
  offset_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBinary::_internal_offset() const {
  return offset_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ReadBinary::offset() const {
  // @@protoc_insertion_point(field_get:cipurse.read_binary.ReadBinary.offset)
  return _internal_offset();
}
inline void ReadBinary::_internal_set_offset(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  offset_ = value;
}
inline void ReadBinary::set_offset(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_offset(value);
  // @@protoc_insertion_point(field_set:cipurse.read_binary.ReadBinary.offset)
}

// -------------------------------------------------------------------

// Binary

// required bytes data = 1;
inline bool Binary::_internal_has_data() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Binary::has_data() const {
  return _internal_has_data();
}
inline void Binary::clear_data() {
  data_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Binary::data() const {
  // @@protoc_insertion_point(field_get:cipurse.read_binary.Binary.data)
  return _internal_data();
}
inline void Binary::set_data(const std::string& value) {
  _internal_set_data(value);
  // @@protoc_insertion_point(field_set:cipurse.read_binary.Binary.data)
}
inline std::string* Binary::mutable_data() {
  // @@protoc_insertion_point(field_mutable:cipurse.read_binary.Binary.data)
  return _internal_mutable_data();
}
inline const std::string& Binary::_internal_data() const {
  return data_.GetNoArena();
}
inline void Binary::_internal_set_data(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Binary::set_data(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:cipurse.read_binary.Binary.data)
}
inline void Binary::set_data(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cipurse.read_binary.Binary.data)
}
inline void Binary::set_data(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cipurse.read_binary.Binary.data)
}
inline std::string* Binary::_internal_mutable_data() {
  _has_bits_[0] |= 0x00000001u;
  return data_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Binary::release_data() {
  // @@protoc_insertion_point(field_release:cipurse.read_binary.Binary.data)
  if (!_internal_has_data()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return data_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Binary::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  data_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:cipurse.read_binary.Binary.data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace read_binary
}  // namespace cipurse

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_cipurse_2fread_5fbinary_2eproto
