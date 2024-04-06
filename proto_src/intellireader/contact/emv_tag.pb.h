// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: contact/emv_tag.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_contact_2femv_5ftag_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_contact_2femv_5ftag_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_contact_2femv_5ftag_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_contact_2femv_5ftag_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_contact_2femv_5ftag_2eproto;
namespace contact {
namespace emv_tag {
class EmvTag;
class EmvTagDefaultTypeInternal;
extern EmvTagDefaultTypeInternal _EmvTag_default_instance_;
}  // namespace emv_tag
}  // namespace contact
PROTOBUF_NAMESPACE_OPEN
template<> ::contact::emv_tag::EmvTag* Arena::CreateMaybeMessage<::contact::emv_tag::EmvTag>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace contact {
namespace emv_tag {

// ===================================================================

class EmvTag :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:contact.emv_tag.EmvTag) */ {
 public:
  EmvTag();
  virtual ~EmvTag();

  EmvTag(const EmvTag& from);
  EmvTag(EmvTag&& from) noexcept
    : EmvTag() {
    *this = ::std::move(from);
  }

  inline EmvTag& operator=(const EmvTag& from) {
    CopyFrom(from);
    return *this;
  }
  inline EmvTag& operator=(EmvTag&& from) noexcept {
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
  static const EmvTag& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EmvTag* internal_default_instance() {
    return reinterpret_cast<const EmvTag*>(
               &_EmvTag_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(EmvTag& a, EmvTag& b) {
    a.Swap(&b);
  }
  inline void Swap(EmvTag* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline EmvTag* New() const final {
    return CreateMaybeMessage<EmvTag>(nullptr);
  }

  EmvTag* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<EmvTag>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const EmvTag& from);
  void MergeFrom(const EmvTag& from);
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
  void InternalSwap(EmvTag* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "contact.emv_tag.EmvTag";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_contact_2femv_5ftag_2eproto);
    return ::descriptor_table_contact_2femv_5ftag_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValueFieldNumber = 2,
    kNumberFieldNumber = 1,
  };
  // required bytes value = 2;
  bool has_value() const;
  private:
  bool _internal_has_value() const;
  public:
  void clear_value();
  const std::string& value() const;
  void set_value(const std::string& value);
  void set_value(std::string&& value);
  void set_value(const char* value);
  void set_value(const void* value, size_t size);
  std::string* mutable_value();
  std::string* release_value();
  void set_allocated_value(std::string* value);
  private:
  const std::string& _internal_value() const;
  void _internal_set_value(const std::string& value);
  std::string* _internal_mutable_value();
  public:

  // required uint32 number = 1;
  bool has_number() const;
  private:
  bool _internal_has_number() const;
  public:
  void clear_number();
  ::PROTOBUF_NAMESPACE_ID::uint32 number() const;
  void set_number(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_number() const;
  void _internal_set_number(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:contact.emv_tag.EmvTag)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr value_;
  ::PROTOBUF_NAMESPACE_ID::uint32 number_;
  friend struct ::TableStruct_contact_2femv_5ftag_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EmvTag

// required uint32 number = 1;
inline bool EmvTag::_internal_has_number() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool EmvTag::has_number() const {
  return _internal_has_number();
}
inline void EmvTag::clear_number() {
  number_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 EmvTag::_internal_number() const {
  return number_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 EmvTag::number() const {
  // @@protoc_insertion_point(field_get:contact.emv_tag.EmvTag.number)
  return _internal_number();
}
inline void EmvTag::_internal_set_number(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  number_ = value;
}
inline void EmvTag::set_number(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_number(value);
  // @@protoc_insertion_point(field_set:contact.emv_tag.EmvTag.number)
}

// required bytes value = 2;
inline bool EmvTag::_internal_has_value() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool EmvTag::has_value() const {
  return _internal_has_value();
}
inline void EmvTag::clear_value() {
  value_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& EmvTag::value() const {
  // @@protoc_insertion_point(field_get:contact.emv_tag.EmvTag.value)
  return _internal_value();
}
inline void EmvTag::set_value(const std::string& value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:contact.emv_tag.EmvTag.value)
}
inline std::string* EmvTag::mutable_value() {
  // @@protoc_insertion_point(field_mutable:contact.emv_tag.EmvTag.value)
  return _internal_mutable_value();
}
inline const std::string& EmvTag::_internal_value() const {
  return value_.GetNoArena();
}
inline void EmvTag::_internal_set_value(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  value_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void EmvTag::set_value(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  value_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:contact.emv_tag.EmvTag.value)
}
inline void EmvTag::set_value(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  value_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:contact.emv_tag.EmvTag.value)
}
inline void EmvTag::set_value(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  value_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:contact.emv_tag.EmvTag.value)
}
inline std::string* EmvTag::_internal_mutable_value() {
  _has_bits_[0] |= 0x00000001u;
  return value_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* EmvTag::release_value() {
  // @@protoc_insertion_point(field_release:contact.emv_tag.EmvTag.value)
  if (!_internal_has_value()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return value_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void EmvTag::set_allocated_value(std::string* value) {
  if (value != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  value_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:contact.emv_tag.EmvTag.value)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace emv_tag
}  // namespace contact

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_contact_2femv_5ftag_2eproto
