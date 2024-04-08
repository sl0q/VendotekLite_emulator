// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/classic/sector/write_sector.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto

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
#include "mifare/classic/sector/sector.pb.h"
#include "mifare/classic/write.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto;
namespace mifare {
namespace classic {
namespace sector {
namespace write {
class WriteSector;
class WriteSectorDefaultTypeInternal;
extern WriteSectorDefaultTypeInternal _WriteSector_default_instance_;
class WriteSectors;
class WriteSectorsDefaultTypeInternal;
extern WriteSectorsDefaultTypeInternal _WriteSectors_default_instance_;
}  // namespace write
}  // namespace sector
}  // namespace classic
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> ::mifare::classic::sector::write::WriteSector* Arena::CreateMaybeMessage<::mifare::classic::sector::write::WriteSector>(Arena*);
template<> ::mifare::classic::sector::write::WriteSectors* Arena::CreateMaybeMessage<::mifare::classic::sector::write::WriteSectors>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mifare {
namespace classic {
namespace sector {
namespace write {

// ===================================================================

class WriteSectors :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.classic.sector.write.WriteSectors) */ {
 public:
  WriteSectors();
  virtual ~WriteSectors();

  WriteSectors(const WriteSectors& from);
  WriteSectors(WriteSectors&& from) noexcept
    : WriteSectors() {
    *this = ::std::move(from);
  }

  inline WriteSectors& operator=(const WriteSectors& from) {
    CopyFrom(from);
    return *this;
  }
  inline WriteSectors& operator=(WriteSectors&& from) noexcept {
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
  static const WriteSectors& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WriteSectors* internal_default_instance() {
    return reinterpret_cast<const WriteSectors*>(
               &_WriteSectors_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(WriteSectors& a, WriteSectors& b) {
    a.Swap(&b);
  }
  inline void Swap(WriteSectors* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WriteSectors* New() const final {
    return CreateMaybeMessage<WriteSectors>(nullptr);
  }

  WriteSectors* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WriteSectors>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const WriteSectors& from);
  void MergeFrom(const WriteSectors& from);
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
  void InternalSwap(WriteSectors* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.classic.sector.write.WriteSectors";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto);
    return ::descriptor_table_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSectorsFieldNumber = 1,
  };
  // repeated .mifare.classic.sector.write.WriteSector sectors = 1;
  int sectors_size() const;
  private:
  int _internal_sectors_size() const;
  public:
  void clear_sectors();
  ::mifare::classic::sector::write::WriteSector* mutable_sectors(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mifare::classic::sector::write::WriteSector >*
      mutable_sectors();
  private:
  const ::mifare::classic::sector::write::WriteSector& _internal_sectors(int index) const;
  ::mifare::classic::sector::write::WriteSector* _internal_add_sectors();
  public:
  const ::mifare::classic::sector::write::WriteSector& sectors(int index) const;
  ::mifare::classic::sector::write::WriteSector* add_sectors();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mifare::classic::sector::write::WriteSector >&
      sectors() const;

  // @@protoc_insertion_point(class_scope:mifare.classic.sector.write.WriteSectors)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mifare::classic::sector::write::WriteSector > sectors_;
  friend struct ::TableStruct_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto;
};
// -------------------------------------------------------------------

class WriteSector :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.classic.sector.write.WriteSector) */ {
 public:
  WriteSector();
  virtual ~WriteSector();

  WriteSector(const WriteSector& from);
  WriteSector(WriteSector&& from) noexcept
    : WriteSector() {
    *this = ::std::move(from);
  }

  inline WriteSector& operator=(const WriteSector& from) {
    CopyFrom(from);
    return *this;
  }
  inline WriteSector& operator=(WriteSector&& from) noexcept {
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
  static const WriteSector& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WriteSector* internal_default_instance() {
    return reinterpret_cast<const WriteSector*>(
               &_WriteSector_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(WriteSector& a, WriteSector& b) {
    a.Swap(&b);
  }
  inline void Swap(WriteSector* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WriteSector* New() const final {
    return CreateMaybeMessage<WriteSector>(nullptr);
  }

  WriteSector* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WriteSector>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const WriteSector& from);
  void MergeFrom(const WriteSector& from);
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
  void InternalSwap(WriteSector* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.classic.sector.write.WriteSector";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto);
    return ::descriptor_table_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSectorFieldNumber = 1,
    kBlocksFieldNumber = 2,
  };
  // required .mifare.classic.sector.sector.Sector sector = 1;
  bool has_sector() const;
  private:
  bool _internal_has_sector() const;
  public:
  void clear_sector();
  const ::mifare::classic::sector::sector::Sector& sector() const;
  ::mifare::classic::sector::sector::Sector* release_sector();
  ::mifare::classic::sector::sector::Sector* mutable_sector();
  void set_allocated_sector(::mifare::classic::sector::sector::Sector* sector);
  private:
  const ::mifare::classic::sector::sector::Sector& _internal_sector() const;
  ::mifare::classic::sector::sector::Sector* _internal_mutable_sector();
  public:

  // required .mifare.classic.write.WriteBlocks blocks = 2;
  bool has_blocks() const;
  private:
  bool _internal_has_blocks() const;
  public:
  void clear_blocks();
  const ::mifare::classic::write::WriteBlocks& blocks() const;
  ::mifare::classic::write::WriteBlocks* release_blocks();
  ::mifare::classic::write::WriteBlocks* mutable_blocks();
  void set_allocated_blocks(::mifare::classic::write::WriteBlocks* blocks);
  private:
  const ::mifare::classic::write::WriteBlocks& _internal_blocks() const;
  ::mifare::classic::write::WriteBlocks* _internal_mutable_blocks();
  public:

  // @@protoc_insertion_point(class_scope:mifare.classic.sector.write.WriteSector)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::mifare::classic::sector::sector::Sector* sector_;
  ::mifare::classic::write::WriteBlocks* blocks_;
  friend struct ::TableStruct_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// WriteSectors

// repeated .mifare.classic.sector.write.WriteSector sectors = 1;
inline int WriteSectors::_internal_sectors_size() const {
  return sectors_.size();
}
inline int WriteSectors::sectors_size() const {
  return _internal_sectors_size();
}
inline void WriteSectors::clear_sectors() {
  sectors_.Clear();
}
inline ::mifare::classic::sector::write::WriteSector* WriteSectors::mutable_sectors(int index) {
  // @@protoc_insertion_point(field_mutable:mifare.classic.sector.write.WriteSectors.sectors)
  return sectors_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mifare::classic::sector::write::WriteSector >*
WriteSectors::mutable_sectors() {
  // @@protoc_insertion_point(field_mutable_list:mifare.classic.sector.write.WriteSectors.sectors)
  return &sectors_;
}
inline const ::mifare::classic::sector::write::WriteSector& WriteSectors::_internal_sectors(int index) const {
  return sectors_.Get(index);
}
inline const ::mifare::classic::sector::write::WriteSector& WriteSectors::sectors(int index) const {
  // @@protoc_insertion_point(field_get:mifare.classic.sector.write.WriteSectors.sectors)
  return _internal_sectors(index);
}
inline ::mifare::classic::sector::write::WriteSector* WriteSectors::_internal_add_sectors() {
  return sectors_.Add();
}
inline ::mifare::classic::sector::write::WriteSector* WriteSectors::add_sectors() {
  // @@protoc_insertion_point(field_add:mifare.classic.sector.write.WriteSectors.sectors)
  return _internal_add_sectors();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mifare::classic::sector::write::WriteSector >&
WriteSectors::sectors() const {
  // @@protoc_insertion_point(field_list:mifare.classic.sector.write.WriteSectors.sectors)
  return sectors_;
}

// -------------------------------------------------------------------

// WriteSector

// required .mifare.classic.sector.sector.Sector sector = 1;
inline bool WriteSector::_internal_has_sector() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || sector_ != nullptr);
  return value;
}
inline bool WriteSector::has_sector() const {
  return _internal_has_sector();
}
inline const ::mifare::classic::sector::sector::Sector& WriteSector::_internal_sector() const {
  const ::mifare::classic::sector::sector::Sector* p = sector_;
  return p != nullptr ? *p : *reinterpret_cast<const ::mifare::classic::sector::sector::Sector*>(
      &::mifare::classic::sector::sector::_Sector_default_instance_);
}
inline const ::mifare::classic::sector::sector::Sector& WriteSector::sector() const {
  // @@protoc_insertion_point(field_get:mifare.classic.sector.write.WriteSector.sector)
  return _internal_sector();
}
inline ::mifare::classic::sector::sector::Sector* WriteSector::release_sector() {
  // @@protoc_insertion_point(field_release:mifare.classic.sector.write.WriteSector.sector)
  _has_bits_[0] &= ~0x00000001u;
  ::mifare::classic::sector::sector::Sector* temp = sector_;
  sector_ = nullptr;
  return temp;
}
inline ::mifare::classic::sector::sector::Sector* WriteSector::_internal_mutable_sector() {
  _has_bits_[0] |= 0x00000001u;
  if (sector_ == nullptr) {
    auto* p = CreateMaybeMessage<::mifare::classic::sector::sector::Sector>(GetArenaNoVirtual());
    sector_ = p;
  }
  return sector_;
}
inline ::mifare::classic::sector::sector::Sector* WriteSector::mutable_sector() {
  // @@protoc_insertion_point(field_mutable:mifare.classic.sector.write.WriteSector.sector)
  return _internal_mutable_sector();
}
inline void WriteSector::set_allocated_sector(::mifare::classic::sector::sector::Sector* sector) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(sector_);
  }
  if (sector) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      sector = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, sector, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  sector_ = sector;
  // @@protoc_insertion_point(field_set_allocated:mifare.classic.sector.write.WriteSector.sector)
}

// required .mifare.classic.write.WriteBlocks blocks = 2;
inline bool WriteSector::_internal_has_blocks() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || blocks_ != nullptr);
  return value;
}
inline bool WriteSector::has_blocks() const {
  return _internal_has_blocks();
}
inline const ::mifare::classic::write::WriteBlocks& WriteSector::_internal_blocks() const {
  const ::mifare::classic::write::WriteBlocks* p = blocks_;
  return p != nullptr ? *p : *reinterpret_cast<const ::mifare::classic::write::WriteBlocks*>(
      &::mifare::classic::write::_WriteBlocks_default_instance_);
}
inline const ::mifare::classic::write::WriteBlocks& WriteSector::blocks() const {
  // @@protoc_insertion_point(field_get:mifare.classic.sector.write.WriteSector.blocks)
  return _internal_blocks();
}
inline ::mifare::classic::write::WriteBlocks* WriteSector::release_blocks() {
  // @@protoc_insertion_point(field_release:mifare.classic.sector.write.WriteSector.blocks)
  _has_bits_[0] &= ~0x00000002u;
  ::mifare::classic::write::WriteBlocks* temp = blocks_;
  blocks_ = nullptr;
  return temp;
}
inline ::mifare::classic::write::WriteBlocks* WriteSector::_internal_mutable_blocks() {
  _has_bits_[0] |= 0x00000002u;
  if (blocks_ == nullptr) {
    auto* p = CreateMaybeMessage<::mifare::classic::write::WriteBlocks>(GetArenaNoVirtual());
    blocks_ = p;
  }
  return blocks_;
}
inline ::mifare::classic::write::WriteBlocks* WriteSector::mutable_blocks() {
  // @@protoc_insertion_point(field_mutable:mifare.classic.sector.write.WriteSector.blocks)
  return _internal_mutable_blocks();
}
inline void WriteSector::set_allocated_blocks(::mifare::classic::write::WriteBlocks* blocks) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(blocks_);
  }
  if (blocks) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      blocks = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, blocks, submessage_arena);
    }
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  blocks_ = blocks;
  // @@protoc_insertion_point(field_set_allocated:mifare.classic.sector.write.WriteSector.blocks)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace write
}  // namespace sector
}  // namespace classic
}  // namespace mifare

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_mifare_2fclassic_2fsector_2fwrite_5fsector_2eproto