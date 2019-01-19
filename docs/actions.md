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
- `OO` vale `99` (novantanove) se l'azione può essere applicata su qualsiasi oggetto.

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

Sono qui riportate tutte le azioni. Ricordando che sono identificate da un codice in formato `LLVVOO`, la colonna "LL" contiene `LL`, la colonna "VV" contiene `VV` e la colonna "OO" contiene `OO`. La colonna "Azione" contiene, invece, il codice del sottoprogramma da eseguire.

|  LL   |  VV   |  OO   | Codice | Azione            |
| :---: | :---: | :---: | -----: | :---------------- |
| `00`  | `01`  | `00`  |    `1` | Spostamento       |
| `00`  | `02`  | `00`  |    `1` | Spostamento       |
| `00`  | `03`  | `00`  |    `1` | Spostamento       |
| `00`  | `04`  | `00`  |    `1` | Spostamento       |
| `00`  | `05`  | `00`  |    `1` | Spostamento       |
| `00`  | `06`  | `00`  |    `1` | Spostamento       |
| `00`  | `08`  | `99`  |   `-2` | Prendi oggetto    |
| `00`  | `09`  | `50`  |  `-10` | azione_x          |
| `00`  | `09`  | `51`  |  `-10` | azione_x          |
| `00`  | `09`  | `99`  |    `3` | Lascia oggetto    |
| `00`  | `10`  | `51`  |  `-11` | azione_x          |
| `00`  | `10`  | `52`  |  `-14` | azione_x          |
| `00`  | `10`  | `53`  |  `-12` | azione_x          |
| `00`  | `10`  | `55`  |  `-13` | azione_x          |
| `00`  | `10`  | `60`  |  `-13` | azione_x          |
| `00`  | `10`  | `99`  |   `-4` | Guarda oggetto    |
| `00`  | `11`  | `00`  |    `5` | Salva             |
| `00`  | `12`  | `00`  |    `6` | Carica            |
| `00`  | `13`  | `00`  |    `7` | Mostra inventario |
| `00`  | `20`  | `50`  |   `-2` | azione_x          |
| `00`  | `20`  | `51`  |   `-2` | azione_x          |
| `00`  | `20`  | `52`  |   `-2` | azione_x          |
| `00`  | `21`  | `50`  |  `-10` | azione_x          |
| `00`  | `21`  | `51`  |  `-10` | azione_x          |
| `00`  | `21`  | `52`  |   `-3` | azione_x          |
| `00`  | `22`  | `55`  |  `-15` | azione_x          |
| `00`  | `25`  | `55`  |  `-15` | azione_x          |
| `00`  | `27`  | `69`  |  `-29` | azione_x          |
| `00`  | `65`  | `50`  |  `-10` | azione_x          |
| `00`  | `65`  | `51`  |  `-10` | azione_x          |
| `00`  | `65`  | `52`  |   `-3` | azione_x          |
| `00`  | `90`  | `00`  |   `90` | Esci              |
| `01`  | `10`  | `66`  |   `16` | azione_x          |
| `01`  | `25`  | `70`  |   `17` | azione_x          |
| `01`  | `26`  | `61`  |   `18` | azione_x          |
| `02`  | `03`  | `00`  |   `21` | azione_x          |
| `02`  | `05`  | `00`  |   `20` | azione_x          |
| `02`  | `25`  | `60`  |   `19` | azione_x          |
| `03`  | `03`  | `00`  |   `21` | azione_x          |
| `04`  | `03`  | `00`  |   `21` | azione_x          |
| `04`  | `25`  | `60`  |   `22` | azione_x          |
| `05`  | `22`  | `67`  |   `23` | azione_x          |
| `06`  | `22`  | `67`  |   `24` | azione_x          |
| `07`  | `03`  | `00`  |   `37` | azione_x          |
| `07`  | `04`  | `00`  |   `38` | azione_x          |
| `07`  | `26`  | `61`  |   `25` | azione_x          |
| `07`  | `26`  | `62`  |   `27` | azione_x          |
| `07`  | `26`  | `64`  |   `26` | azione_x          |
| `08`  | `10`  | `66`  |   `16` | azione_x          |
| `08`  | `23`  | `65`  |   `35` | azione_x          |
| `08`  | `24`  | `65`  |   `34` | azione_x          |
| `08`  | `25`  | `60`  |   `28` | azione_x          |
| `08`  | `26`  | `61`  |   `30` | azione_x          |
| `08`  | `26`  | `62`  |   `33` | azione_x          |
| `08`  | `26`  | `63`  |   `32` | azione_x          |
| `08`  | `26`  | `64`  |   `31` | azione_x          |
| `09`  | `10`  | `69`  |   `36` | azione_x          |
