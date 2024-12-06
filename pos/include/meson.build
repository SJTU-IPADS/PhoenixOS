# Copyright 2024 The PhoenixOS Authors. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

log_conf = configuration_data()
eval_conf = configuration_data()
runtime_conf = configuration_data()


# ==================== log ====================
log_conf.set('conf_runtime_enable_print_error', conf_runtime_enable_print_error)
log_conf.set('conf_runtime_enable_print_warn', conf_runtime_enable_print_warn)
log_conf.set('conf_runtime_enable_print_log', conf_runtime_enable_print_log)
log_conf.set('conf_runtime_enable_print_debug', conf_runtime_enable_print_debug)
log_conf.set('conf_runtime_enable_print_with_color', conf_runtime_enable_print_with_color)
configure_file(input : 'log.h.in', output : 'log.h', configuration : log_conf)


# ==================== runtime configs ====================
runtime_conf.set('conf_runtime_default_daemon_log_path', conf_runtime_default_daemon_log_path)
runtime_conf.set('conf_runtime_default_client_log_path', conf_runtime_default_client_log_path)
runtime_conf.set('conf_runtime_enable_debug_check', conf_runtime_enable_debug_check)
runtime_conf.set('conf_runtime_enable_hijack_api_check', conf_runtime_enable_hijack_api_check)
runtime_conf.set('conf_runtime_enable_trace', conf_runtime_enable_trace)
runtime_conf.set('conf_runtime_enable_memory_trace', conf_runtime_enable_memory_trace)
configure_file(input : 'runtime_configs.h.in', output : 'runtime_configs.h', configuration : runtime_conf)


# ==================== eval configs ====================
eval_conf.set('conf_eval_ckpt_opt_level', conf_eval_ckpt_opt_level)
eval_conf.set('conf_eval_ckpt_enable_increamental', conf_eval_ckpt_enable_increamental)
eval_conf.set('conf_eval_ckpt_enable_pipeline', conf_eval_ckpt_enable_pipeline)
eval_conf.set('conf_eval_default_ckpt_interval_ms', conf_eval_default_ckpt_interval_ms)
eval_conf.set('conf_eval_migr_opt_level', conf_eval_migr_opt_level)
eval_conf.set('conf_eval_rst_enable_context_pool', conf_eval_rst_enable_context_pool)
configure_file(input : 'eval_configs.h.in', output : 'eval_configs.h', configuration : eval_conf)
