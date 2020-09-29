# ARM Processor Builds

subdir('arch')
subdir('drivers')
subdir('utilities')

# TODO: should this linker stuff be overrideable by the user, instead of fixed?
arm_dep = declare_dependency(
	dependencies:
	[
        arm_arch_dep,
		arm_common_drivers_dep,
        arm_common_utilties_dep
	],
	link_args: [
		# So the application linker script can pick up gcc_arm_common.ld
		'-L' + meson.current_source_dir() / 'linker',
	]
)
