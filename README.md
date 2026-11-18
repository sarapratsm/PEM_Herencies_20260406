# Herències en C++ (PEM)

Pràctiques d'herència i polimorfisme en C++ per a l'assignatura de Programació Estructurada i Modular (PEM) del CFGS de Desenvolupament d'Aplicacions Multiplataforma (Institut Milà i Fontanals, Igualada). La solució és `HerenciesCpp.slnx` (Visual Studio).

## Projectes

### Supermercat (`20260406_Supermercat`)

Jerarquia de productes d'un supermercat:

- `Producte`: classe base amb nom, preus de compra i venda i data d'alta. Té destructor i mètode `visualitzar()` virtuals.
- `Aliment` i `Neteja`: classes derivades amb les seves dades pròpies, que sobreescriuen `visualitzar()`.
- Versions `*_UniPtr` (`Producte_UniPtr`, `Aliment_UniPtr`, `Neteja_UniPtr`): la mateixa jerarquia gestionant la memòria amb `std::unique_ptr` en lloc de `new`/`delete` manuals.

### Propietats (`20260423_Propietats`)

Jerarquia d'immobles: `Propietat` (classe base), `PropietatEnLloguer` i `PropietatEnVenda` (classes derivades `final`) i `TipusPropietat`.

## Conceptes que es practiquen

- Herència pública i constructors de les classes derivades.
- Mètodes virtuals i polimorfisme.
- Gestió de memòria dinàmica: còpia profunda i regla dels tres, o bé punters intel·ligents (`unique_ptr`).
- Atributs opcionals i validació de dades.

## Compilació

Obre `HerenciesCpp.slnx` amb Visual Studio 2022 o superior (toolset C++ v143) i compila el projecte que vulguis executar.
