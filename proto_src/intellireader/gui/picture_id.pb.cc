// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gui/picture_id.proto

#include "gui/picture_id.pb.h"

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
namespace gui {
namespace picture_id {
}  // namespace picture_id
}  // namespace gui
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_gui_2fpicture_5fid_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_gui_2fpicture_5fid_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_gui_2fpicture_5fid_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_gui_2fpicture_5fid_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_gui_2fpicture_5fid_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024gui/picture_id.proto\022\016gui.picture_id*\255"
  "\001\n\tPictureId\022\014\n\010APPROVED\020\000\022\014\n\010REJECTED\020\001"
  "\022\032\n\026EMV_CONTACTLESS_SYMBOL\020\002\022\014\n\010AWAITING"
  "\020\003\022\025\n\021APPROVED_DISCOUNT\020\004\022\023\n\017MASTERCARD_"
  "LOGO\020\n\022\r\n\tVISA_LOGO\020\013\022\014\n\010MIR_LOGO\020\014\022\021\n\rU"
  "NIONPAY_LOGO\020\r"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_gui_2fpicture_5fid_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_gui_2fpicture_5fid_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_gui_2fpicture_5fid_2eproto_once;
static bool descriptor_table_gui_2fpicture_5fid_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_gui_2fpicture_5fid_2eproto = {
  &descriptor_table_gui_2fpicture_5fid_2eproto_initialized, descriptor_table_protodef_gui_2fpicture_5fid_2eproto, "gui/picture_id.proto", 214,
  &descriptor_table_gui_2fpicture_5fid_2eproto_once, descriptor_table_gui_2fpicture_5fid_2eproto_sccs, descriptor_table_gui_2fpicture_5fid_2eproto_deps, 0, 0,
  schemas, file_default_instances, TableStruct_gui_2fpicture_5fid_2eproto::offsets,
  file_level_metadata_gui_2fpicture_5fid_2eproto, 0, file_level_enum_descriptors_gui_2fpicture_5fid_2eproto, file_level_service_descriptors_gui_2fpicture_5fid_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_gui_2fpicture_5fid_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_gui_2fpicture_5fid_2eproto), true);
namespace gui {
namespace picture_id {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PictureId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_gui_2fpicture_5fid_2eproto);
  return file_level_enum_descriptors_gui_2fpicture_5fid_2eproto[0];
}
bool PictureId_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 10:
    case 11:
    case 12:
    case 13:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace picture_id
}  // namespace gui
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>