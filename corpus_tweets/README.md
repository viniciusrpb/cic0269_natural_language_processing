# Tweet corpus

## Arquivos

- **SemEval2014-task3-train-valid.txt:** corpus completo, contendo os tweets de treinamento e teste (ver na seço abaixo como diferenciar os tweets de treinamento dos de teste);
- **SemEval2014-task3-train.txt:** corpus dos tweets de treinamento apenas;
- **SemEval2014-task3-valid.txt:** corpus dos tweets de validação (pode ser usado para teste) apenas;

## Atributos

- text
- label: positive, negative e neutral
- is_valid : flag (*True* ou *False*) para dizer se um tweet é do conjunto de treinamento ou validação (teste). Campo existente apenas no arquivo *SemEval2014-task3-train-valid.txt*;

