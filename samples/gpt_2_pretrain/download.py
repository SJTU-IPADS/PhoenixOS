# from transformers import GPT2Tokenizer
# tokenizer = GPT2Tokenizer.from_pretrained('openai-community/gpt2-xl')
# tokenizer.save_pretrained('./tokenizer_xl/')

# from transformers import GPT2LMHeadModel
# model = GPT2LMHeadModel.from_pretrained('openai-community/gpt2-xl')
# model.save_pretrained('./model_xl')

from transformers import GPT2Tokenizer
tokenizer = GPT2Tokenizer.from_pretrained('openai-community/gpt2')
tokenizer.save_pretrained('./tokenizer/')

from transformers import GPT2LMHeadModel
model = GPT2LMHeadModel.from_pretrained('openai-community/gpt2')
model.save_pretrained('./model')
