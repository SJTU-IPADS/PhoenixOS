#  API Interceptor Generator for CUDAM

## Usage

This tool helps to generate interceptor template for CUDA runtime APIs. To use:

1. prepare environments:

```bash
pip install pygccxml castxml jinja2
```

2. copy header file to `headers`, and remember to setup cuda path within `global_config.py`

3. run script, the output file is locate default in `api_interceptor_gen/output`

```bash
python ./main.py 
```
