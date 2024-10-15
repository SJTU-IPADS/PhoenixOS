switches_conf = configuration_data()
config_conf = configuration_data()

# ==================== switches ====================
switches_conf.set('pos_enable_debug_check', enable_runtime_debug_check)
switches_conf.set('pos_enable_hijack_api_check', enable_hijack_api_check)
switches_conf.set('pos_enable_trace', enable_trace)
configure_file(input : 'switches.h.in', output : 'switches.h', configuration : switches_conf)


# ==================== configs ====================
# common configurations
config_conf.set('pos_tsc_freq', tsc_reg_freq)
config_conf.set('pos_log_file_path', log_file_path)

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

configure_file(input : 'config.h.in', output : 'config.h', configuration : config_conf)
