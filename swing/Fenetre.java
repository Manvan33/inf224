
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// Main window, extending JFrame
public class Fenetre extends JFrame {

    private static final long serialVersionUID = 1L;
    private JLabel output_line;
    private TCPClient tcp;


    // Constructor
    public Fenetre() {
        // Set window title
        this.setTitle("Super télécommande :)");
        // Set window default close operation
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
        // Add menu bar
        JMenuBar barre_menu = new JMenuBar();
        JMenu menu_fichier = new JMenu("Fichier");
        menu_fichier.setMnemonic(KeyEvent.VK_F);
        JMenuItem menu_fichier_quitter = new JMenuItem("Quitter");
        menu_fichier_quitter.setMnemonic(KeyEvent.VK_Q);
        menu_fichier_quitter.addActionListener(new QuitListener());
        menu_fichier.add(menu_fichier_quitter);
        barre_menu.add(menu_fichier);
        setJMenuBar(barre_menu);
        JTextPane welcome = new JTextPane();
        welcome.setText("Bienvenue dans la télécommande. " +
                "\nLes éléments média existants sont : \n- image.gif \n- video.webm" +
                "\nLes groupes existants sont : \n- photos \n- videos \n- main_group");
        welcome.setEditable(false);
        add(welcome);
        add(connection_section());
        add(generic_section("Objets multimédia", "search", "play"));
        add(generic_section("Groupes", "search_group", "play_group"));
        JPanel output_panel = new JPanel();
        output_panel.setLayout(new GridLayout(1, 2));
        output_line = new JLabel("Non connecté au serveur");
        output_panel.add(output_line);
        add(output_panel);

        pack();
        // Set window visibility
        this.setVisible(true);

    }

    private JPanel connection_section() {
        JPanel connection = new JPanel();
        connection.add(new JLabel("Adresse IP :"));
        JTextField ip_field = new JTextField("localhost", 20);
        connection.add(ip_field);
        connection.add(new JLabel("Port :"));
        JTextField port_field = new JTextField("3331", 10);
        connection.add(port_field);
        JButton connect_button = new JButton("Connexion");
        connection.add(connect_button);
        connect_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (tcp != null) {
                        tcp.send("stop");
                        tcp.close();
                        tcp = null;
                        connect_button.setText("Connexion");
                        output_line.setText("Déconnecté");
                    } else {
                        tcp = new TCPClient(ip_field.getText(), Integer.parseInt(port_field.getText()));
                        output_line.setText("Connecté au serveur");
                        connect_button.setText("STOP");
                    }
                } catch (Exception ex) {
                    output_line.setText("Erreur de connexion");
                }
            }
        });
        return connection;
    }

    private JComponent generic_section(String title, String search_command, String play_command) {
        JPanel panel = new JPanel();
        panel.setBorder(BorderFactory.createTitledBorder(title));
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        JPanel tools_panel = new JPanel();
        JTextField search_field = new JTextField(20);
        JButton search_button = new JButton("Rechercher");
        JButton play_button = new JButton("Jouer");
        tools_panel.add(search_field);
        tools_panel.add(search_button);
        tools_panel.add(play_button);
        panel.add(tools_panel, BorderLayout.CENTER);
        JTextArea text_area = new JTextArea(10, 40);
        text_area.setEditable(false);
        search_button.addActionListener(new TcpCommand(search_command, search_field, text_area));
        play_button.addActionListener(new TcpCommand(play_command, search_field, text_area));
        panel.add(new JScrollPane(text_area), BorderLayout.SOUTH);
        return panel;
    }

    private void set_output_line(String text) {
        output_line.setText(text);
    }

    private class TcpCommand implements ActionListener {
        private String command;
        private JTextField input;
        private JTextArea output;

        public TcpCommand(String command, JTextField input, JTextArea output) {
            this.command = command;
            this.input = input;
            this.output = output;
        }

        public void actionPerformed(ActionEvent e) {
            try {
                if (tcp == null) {
                    set_output_line("Non connecté au serveur");
                    this.output.setText("Non connecté au serveur");
                    return;
                }
                String response = tcp.send(this.command + " " + this.input.getText());
                output_line.setText("Commande envoyée : " + this.command + " " + this.input.getText());
                this.output.setText(response.replace(", ", "\n"));
            } catch (Exception ex) {
                output_line.setText("Erreur de connexion");
            }
        }
    }

    private static class QuitListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
