switches_conf = configuration_data()
log_conf = configuration_data()
config_conf = configuration_data()

switches_conf.set('pos_enable_debug_check', enable_runtime_debug_check)
switches_conf.set('pos_enable_hijack_api_check', enable_hijack_api_check)
switches_conf.set('pos_enable_trace', enable_trace)
configure_file(input : 'switches.h.in', output : 'switches.h', configuration : switches_conf)

log_conf.set('pos_print_error', enable_print_error)
log_conf.set('pos_print_warn', enable_print_warn)
log_conf.set('pos_print_log', enable_print_log)
log_conf.set('pos_print_debug', enable_print_debug)
log_conf.set('pos_print_with_color', enable_print_with_color)
configure_file(input : 'log.h.in', output : 'log.h', configuration : log_conf)

config_conf.set('pos_tsc_freq', tsc_reg_freq)

# for continuous checkpoint
config_conf.set('pos_ckpt_opt_level', ckpt_opt_level)
config_conf.set('pos_enable_ckpt_increamental', enable_ckpt_increamental)
config_conf.set('pos_enable_ckpt_pipeline', enable_ckpt_pipeline)
config_conf.set('pos_enable_ckpt_orchestration', enable_ckpt_orchestration)
config_conf.set('pos_ckpt_interval_ms', ckpt_interval_ms)

# for migration
config_conf.set('pos_migration_opt_level', migration_opt_level)

# others
config_conf.set('pos_enable_context_pool', enable_context_pool)

config_conf.set('pos_log_file_path', log_file_path)
configure_file(input : 'config.h.in', output : 'config.h', configuration : config_conf)
