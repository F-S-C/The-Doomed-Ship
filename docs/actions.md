# Le azioni

Nel gioco, ogni azione è codificata da un numero a sei cifre. A ognuno di questi codici è legato un identificatore dell'azione da eseguire.

I codici delle azioni sono nel formato `LLVVOO`, dove:

- `LL` è il codice del luogo in cui attuare l'azione
- `VV` è il codice del verbo che identifica l'azione
- `OO` è il codice dell'oggetto interessato dall'azione

Ogni comando impartito dall'utente è tradotto in un codice nel formato `LLVVOO`, che viene poi ricercato nella tavola delle azioni seguente.

Tutte le possibili azioni sono memorizzate nel gioco tramite il relativo codice del comando, utilizzando le seguenti regole:

- Tutte le regole precedenti
- `LL` vale `0` (zero) se l'azione può essere attuata in qualsiasi luogo
- `OO` vale `0` (zero) se l'azione non richiede oggetti
- `OO` vale `99` (novantanove) se l'azione può esssere applicata su qualsiasi oggetto.

Ogni comando `LLVVOO` viene ricercato nella tavola delle azioni nel seguente modo:

1. Si ricerca il comando `LLVVOO`
2. Se non si è trovato, si ricerca `00LLOO`
3. Se non si è trovato, si ricerca `LLVV99`
4. Se non si è trovato, si ricerca `00LL99`

A ogni azione è poi associato l'identificatore che determina il sottoprogramma da eseguire. Tale identificatore è un _intero_ a cui è associato il seguente significato:

- Il suo valore assoluto è il numero identificativo del sottoprogramma da eseguire
- Se è positivo, l'oggetto a cui si riferisce l'azione può non essere presente nello stesso luogo del personaggio
- Se è negativo, l'oggetto a cui si riverisce l'azione _deve_ essere presente nello stesso luogo del personaggio

## Tavola delle azioni

Sono qui riportate tutte le azioni. Ricordando che sono identificate da un codice in formato `LLVVOO`, la colonna "Luogo" contiene `LL`, la colonna "Verbo" contiene `VV` e la colonna "Oggetto" contiene `OO`. La colonna "Azione" contiene, invece, il codice del sottoprogramma da eseguire.

| Luogo | Verbo | Oggetto | Azione |
| :---: | :---: | :-----: | -----: |
| `00`  | `01`  |  `00`   |    `1` |
| `00`  | `02`  |  `00`   |    `1` |
| `00`  | `03`  |  `00`   |    `1` |
| `00`  | `04`  |  `00`   |    `1` |
| `00`  | `05`  |  `00`   |    `1` |
| `00`  | `06`  |  `00`   |    `1` |
| `00`  | `08`  |  `99`   |   `-2` |
| `00`  | `09`  |  `50`   |  `-10` |
| `00`  | `09`  |  `51`   |  `-10` |
| `00`  | `09`  |  `99`   |    `3` |
| `00`  | `10`  |  `51`   |  `-11` |
| `00`  | `10`  |  `52`   |  `-14` |
| `00`  | `10`  |  `53`   |  `-12` |
| `00`  | `10`  |  `55`   |  `-13` |
| `00`  | `10`  |  `60`   |  `-13` |
| `00`  | `10`  |  `99`   |   `-4` |
| `00`  | `11`  |  `00`   |    `5` |
| `00`  | `12`  |  `00`   |    `6` |
| `00`  | `13`  |  `00`   |    `7` |
| `00`  | `20`  |  `50`   |   `-2` |
| `00`  | `20`  |  `51`   |   `-2` |
| `00`  | `20`  |  `52`   |   `-2` |
| `00`  | `21`  |  `50`   |  `-10` |
| `00`  | `21`  |  `51`   |  `-10` |
| `00`  | `21`  |  `52`   |   `-3` |
| `00`  | `22`  |  `55`   |  `-15` |
| `00`  | `25`  |  `55`   |  `-15` |
| `00`  | `27`  |  `69`   |  `-29` |
| `00`  | `65`  |  `50`   |  `-10` |
| `00`  | `65`  |  `51`   |  `-10` |
| `00`  | `65`  |  `52`   |   `-3` |
| `00`  | `90`  |  `00`   |   `90` |
| `01`  | `10`  |  `66`   |   `16` |
| `01`  | `25`  |  `70`   |   `17` |
| `01`  | `26`  |  `61`   |   `18` |
| `02`  | `03`  |  `00`   |   `21` |
| `02`  | `05`  |  `00`   |   `20` |
| `02`  | `25`  |  `60`   |   `19` |
| `03`  | `03`  |  `00`   |   `21` |
| `04`  | `03`  |  `00`   |   `21` |
| `04`  | `25`  |  `60`   |   `22` |
| `05`  | `22`  |  `67`   |   `23` |
| `06`  | `22`  |  `67`   |   `24` |
| `07`  | `03`  |  `00`   |   `37` |
| `07`  | `04`  |  `00`   |   `38` |
| `07`  | `26`  |  `61`   |   `25` |
| `07`  | `26`  |  `62`   |   `27` |
| `07`  | `26`  |  `64`   |   `26` |
| `08`  | `10`  |  `66`   |   `16` |
| `08`  | `23`  |  `65`   |   `35` |
| `08`  | `24`  |  `65`   |   `34` |
| `08`  | `25`  |  `60`   |   `28` |
| `08`  | `26`  |  `61`   |   `30` |
| `08`  | `26`  |  `62`   |   `33` |
| `08`  | `26`  |  `63`   |   `32` |
| `08`  | `26`  |  `64`   |   `31` |
| `09`  | `10`  |  `69`   |   `36` |