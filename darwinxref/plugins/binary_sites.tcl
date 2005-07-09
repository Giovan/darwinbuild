DBPluginSetName binary_sites
DBPluginSetType property
DBPluginSetDatatype array

proc usage {} {
	return {[<project>]}
}

proc run {args} {
	set project [lindex $args 0]
	set build [DBGetCurrentBuild]
	foreach site [DBCopyPropArray $build $project binary_sites] {
		puts "$site"
	}
}
