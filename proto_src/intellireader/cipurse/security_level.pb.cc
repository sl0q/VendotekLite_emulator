// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cipurse/security_level.proto

#include "cipurse/security_level.pb.h"

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
namespace cipurse {
namespace security_level {
}  // namespace security_level
}  // namespace cipurse
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_cipurse_2fsecurity_5flevel_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_cipurse_2fsecurity_5flevel_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_cipurse_2fsecurity_5flevel_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_cipurse_2fsecurity_5flevel_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_cipurse_2fsecurity_5flevel_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\034cipurse/security_level.proto\022\026cipurse."
  "security_level*7\n\rSecurityLevel\022\014\n\010SM_PL"
  "AIN\020\000\022\t\n\005MACED\020\001\022\r\n\tENCRYPTED\020\002"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_cipurse_2fsecurity_5flevel_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_cipurse_2fsecurity_5flevel_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_cipurse_2fsecurity_5flevel_2eproto_once;
static bool descriptor_table_cipurse_2fsecurity_5flevel_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cipurse_2fsecurity_5flevel_2eproto = {
  &descriptor_table_cipurse_2fsecurity_5flevel_2eproto_initialized, descriptor_table_protodef_cipurse_2fsecurity_5flevel_2eproto, "cipurse/security_level.proto", 111,
  &descriptor_table_cipurse_2fsecurity_5flevel_2eproto_once, descriptor_table_cipurse_2fsecurity_5flevel_2eproto_sccs, descriptor_table_cipurse_2fsecurity_5flevel_2eproto_deps, 0, 0,
  schemas, file_default_instances, TableStruct_cipurse_2fsecurity_5flevel_2eproto::offsets,
  file_level_metadata_cipurse_2fsecurity_5flevel_2eproto, 0, file_level_enum_descriptors_cipurse_2fsecurity_5flevel_2eproto, file_level_service_descriptors_cipurse_2fsecurity_5flevel_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_cipurse_2fsecurity_5flevel_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_cipurse_2fsecurity_5flevel_2eproto), true);
namespace cipurse {
namespace security_level {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SecurityLevel_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_cipurse_2fsecurity_5flevel_2eproto);
  return file_level_enum_descriptors_cipurse_2fsecurity_5flevel_2eproto[0];
}
bool SecurityLevel_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace security_level
}  // namespace cipurse
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
