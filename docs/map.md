# La mappa di gioco

## I luoghi

Questa è una lista di tutti i luoghi della mappa di gioco. Ogni luogo è identificato da un ID numerico e un nome. Per ogni luogo, è fornita una breve descrizione.

<dl>
    <dt>01: Cabina di pilotaggio</dt>
    <dd>
        La cabina di pilotaggio dell'astronave.
    </dd>
    <dt>02: Estremità del corridoio</dt>
    <dd>
        L'estremità nord del corridoio.
    </dd>
    <dt>03: Il corridoio</dt>
    <dd>
        Il corridoio principale dell'astronave.
    </dd>
    <dt>04: Estremità del corridoio</dt>
    <dd>
        L'estremità sud del corridoio.
    </dd>
    <dt>05: Cabina del secondo pilota</dt>
    <dd>
        La cabina del secondo pilota.
    </dd>
    <dt>06: Cabina</dt>
    <dd>
        La cabina del personaggio della storia. È il luogo di inizio del gioco.
    </dd>
    <dt>07: Compartimento stagno</dt>
    <dd>
        Il compartimento stagno rende sicuro l'accesso all'esterno dell'astronave.
    </dd>
    <dt>08: Sala di controllo del reattore</dt>
    <dd>
        La sala di controllo del reattore.
    </dd>
    <dt>09: Esterno &ndash; prua dell'astronave</dt>
    <dd>
        L'esterno dell'astronave (nord).
    </dd>
    <dt>10: Esterno</dt>
    <dd>
        L'esterno dell'astronave.
    </dd>
    <dt>11: Esterno &ndash; poppa dell'astronave</dt>
    <dd>
        L'esterno dell'astronave (sud).
    </dd>
</dl>

## Il grafo
<figure>
    <figcaption>
        <strong>Legenda:</strong><br />
        <ul>
            <li>Una linea continua indica che la direzione può essere presa in ogni momento.</li>
            <li>Una linea tratteggiata indica che la direzione può essere presa solo se sono verificate determinate condizioni.</li>
            <li>
                Le cuspidi rappresentano le direzioni. Se non diversamente specificato, le direzioni sono le seguenti:
                <ul>
                    <li><strong>Nord</strong>: su</li>
                    <li><strong>Est</strong>: destra</li>
                    <li><strong>Sud</strong>: giù</li>
                    <li><strong>Ovest</strong>: sinistra</li>
                </ul>
            </li>
            <li>Se una freccia è etichettata, l'etichetta è riferita alla cuspide più vicina. Un etichetta può contenere informazioni sulla direzione del passaggio o sulla condizione che va verificata per effettuare quello spostamento.</li>
        </ul>
    </figcaption>
    <img src="./assets/images/map.svg" alt="Il grafo della mappa" />
</figure>