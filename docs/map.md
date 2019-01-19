# La mappa di gioco

## I luoghi

Questa è una lista di tutti i luoghi della mappa di gioco. Ogni luogo è identificato da un ID numerico e un nome. Per ogni luogo, è fornita una breve descrizione.

<dl>
    <dt>01: Cabina di pilotaggio</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L01.png" alt="Place 01" />-->
        </figure>
    </dd>
    <dt>02: Estremità del corridoio</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L02.png" alt="Place 02" />-->
        </figure>
    </dd>
    <dt>03: Il corridoio</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L03.png" alt="Place 03" />-->
        </figure>
    </dd>
    <dt>04: Estremità del corridoio</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L04.png" alt="Place 04" />-->
        </figure>
    </dd>
    <dt>05: Cabina del secondo pilota</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L05.png" alt="Place 05" />-->
        </figure>
    </dd>
    <dt>06: Cabina</dt>
    <dd>
        <figure>
            <figcaption>The player's cabin. It's the game starting point.</figcaption>
            <img src="./images/Screenshots/L06.png" alt="Place 06" />
        </figure>
    </dd>
    <dt>07: Compartimento stagno</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L07.png" alt="Place 07" />-->
        </figure>
    </dd>
    <dt>08: Sala di controllo del reattore</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L08.png" alt="Place 08" />-->
        </figure>
    </dd>
    <dt>09: Esterno &ndash; prua dell'astronave</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L09.png" alt="Place 09" />-->
        </figure>
    </dd>
    <dt>10: Esterno</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L10.png" alt="Place 10" />-->
        </figure>
    </dd>
    <dt>11: Esterno &ndash; poppa dell'astronave</dt>
    <dd>
        <figure>
            <!--<figcaption>The player's cabin</figcaption>
            <img src="./images/Screenshots/L11.png" alt="Place 11" />-->
        </figure>
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
    <img src="./images/map.svg" alt="Il grafo della mappa" />
</figure>