1) Transforme o DER em esquema físico (SQL).
Situação:

ALUNO é orientado por um PROFESSOR.
PROFESSOR possui uma TITULAÇÃO.

Resposta perfeita:
CREATE TABLE titulacao (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

CREATE TABLE professor (
    prontuario SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    titulacao_id INT REFERENCES titulacao(id)
);

CREATE TABLE aluno (
    ra SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    professor_prontuario INT REFERENCES professor(prontuario)
);

2) Inserir dados nas tabelas
Resposta:
INSERT INTO titulacao (nome)
VALUES ('Mestre'), ('Doutor');

INSERT INTO professor (nome, titulacao_id)
VALUES ('Carlos', 1), ('Marina', 2);

INSERT INTO aluno (nome, professor_prontuario)
VALUES ('Julia', 1), ('Rafael', 2), ('Ana', NULL);

3) Consulta com JOIN: listar aluno + professor
SELECT a.nome AS aluno,
       p.nome AS professor
FROM aluno a
JOIN professor p
     ON a.professor_prontuario = p.prontuario;

4) Consulta com restrição

Alunos que têm orientador:

SELECT *
FROM aluno
WHERE professor_prontuario IS NOT NULL;

5) FULL OUTER JOIN (cai MUITO)

Mostrar todos alunos e todos professores, com ou sem vínculo.

SELECT a.nome AS aluno,
       p.nome AS professor
FROM aluno a
FULL OUTER JOIN professor p
     ON a.professor_prontuario = p.prontuario;

6) Atualização de dados

Mudar o professor da Julia:

UPDATE aluno
SET professor_prontuario = 2
WHERE nome = 'Julia';

7) Delete com restrição

Excluir aluno que não tem orientador:

DELETE FROM aluno
WHERE professor_prontuario IS NULL;

⭐ PARTE 2 — MINI TEORIA QUE CAI (respostas curtas)
O que é AS?

Apelido para tabela ou coluna.

O que é JOIN?

Combina dados de duas tabelas relacionadas.

Tipos de JOIN (resumo de ouro):
JOIN	O que retorna
INNER	Apenas os que têm correspondência
LEFT	Tudo da esquerda
RIGHT	Tudo da direita
FULL	Tudo de ambos
Consulta com restrição

SELECT + WHERE
