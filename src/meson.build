# ARM Processor Builds

cmsis_corem_include = include_directories('CMSIS_5/CMSIS/Core/Include', is_system: true)

arm_directory_root = meson.current_source_dir()
gcc_arm_common_linker_script = files('gcc_arm_common.ld')

subdir('arch')
subdir('drivers')
subdir('utilities')

arm_dep = declare_dependency(
	dependencies:
	[
        arm_arch_dep,
		arm_common_drivers_dep,
        arm_common_utilties_dep
	]
)

arm_common_includes = include_directories('utilities')

subdir('nordic')
