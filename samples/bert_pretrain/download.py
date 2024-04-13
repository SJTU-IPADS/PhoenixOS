from transformers import BertTokenizer
tokenizer = BertTokenizer.from_pretrained('bert-large-cased')
tokenizer.save_pretrained('./tokenizer')

from transformers import BertModel
model = BertModel.from_pretrained('bert-large-cased')
model.save_pretrained('./model')
