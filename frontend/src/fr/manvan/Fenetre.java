package fr.manvan;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// Main window, extending JFrame
public class Fenetre extends JFrame {
    JButton bouton_oui, bouton_non, bouton_quit;
    JTextArea zoneTexte;
    JPanel boiteBoutons;
    private static final long serialVersionUID = 1L;

    // Constructor
    public Fenetre() {
        // Set window title
        this.setTitle("Et oui et non");
        // Set window default close operation
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        zoneTexte = new JTextArea(10, 40);
        zoneTexte.setText("Bonjour monde !\n");
        add(new JScrollPane(zoneTexte), BorderLayout.CENTER);
        boiteBoutons = new JPanel();
        boiteBoutons.setLayout(new GridLayout(1, 3));

        boiteBoutons.add(bouton_oui = new JButton("Oui"));
        boiteBoutons.add(bouton_non = new JButton("Non"));
        boiteBoutons.add(bouton_quit = new JButton("Quitter"));
        bouton_non.addActionListener(new AddTextListener("Non\n"));
        bouton_oui.addActionListener(new AddTextListener("Oui\n"));
        bouton_quit.addActionListener(new QuitListener());

        add(boiteBoutons, BorderLayout.SOUTH);
        pack();
        // Set window visibility
        this.setVisible(true);
    }

    private class AddTextListener implements ActionListener {
        private final String a_ajouter;
        public void actionPerformed(ActionEvent e) {
            zoneTexte.setText(zoneTexte.getText()+a_ajouter);
        }
        public AddTextListener(String a_ajouter) {
            this.a_ajouter = a_ajouter;
        }
    }
    private static class QuitListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
