package com.fsc.the_doomed_ship.game.strings;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class StringDictionary {

    private Map<String, String> map;

    public StringDictionary(String file) {
        map = new HashMap<>();
        File xmlFile = new File(file);

        try {
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.parse(xmlFile);

            document.getDocumentElement().normalize();

            Node node = document.getElementsByTagName("menu").item(0);
            if (node.getNodeType() == Node.ELEMENT_NODE) {
                NodeList nodeList = ((Element) node).getElementsByTagName("item");
                for (int i = 0; i < nodeList.getLength(); i++) {
                    Node node2 = nodeList.item(i);
                    String string = node2.getTextContent();
                    String key = node2.getAttributes().getNamedItem("name").getTextContent();
                    put(key, string);
                }
            }
            node = document.getElementsByTagName("story").item(0);
            if (node.getNodeType() == Node.ELEMENT_NODE) {
                NodeList nodeList = ((Element) node).getElementsByTagName("item");
                for (int i = 0; i < nodeList.getLength(); i++) {
                    Node node2 = nodeList.item(i);
                    String string = node2.getTextContent();
                    String key = node2.getAttributes().getNamedItem("name").getTextContent();
                    put(key, string);
                }
            }
        } catch (SAXException | IOException | ParserConfigurationException e) {
            e.printStackTrace();
        }
    }

    public String get(Enum name){
        return map.get(name.toString());
    }

    public int size() {
        return map.size();
    }

    public void put(String key, String string){
        string = string.replace("\\n", "\n");
        map.put(key, string);
    }
}
