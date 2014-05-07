//Aaron Martin
//Display Class
//Rock Paper Scissors

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;


/**
 *
 * @author blackie
 */
public class Display extends JFrame {
    
    //Window Height and Width
    private static final int FRAME_HEIGHT = 200;
    private static final int FRAME_WIDTH = 500;
    private static int playerIntScore = 0;
    private static int computerIntScore = 0;
    
    private static char characterFlag;
    
    //Window
    private JPanel buttonPanel;
    private JPanel scorePanel;
    
    //Buttons
    private JButton rock;
    private JButton paper;
    private JButton scissors;
    
    //Labels
    private JLabel currentStatus;
    private JLabel playerScore;
    private JLabel computerScore;
    private RockPaperShotgun theGame;
    
    public static void main(String[] args)
    {
        JFrame displayFrame = new Display();
        displayFrame.setVisible(true);
    }
    
    public Display()
    {
        //Creates Display
        setSize(FRAME_WIDTH,FRAME_HEIGHT);
        setTitle("Rock Paper Scissors");
        setLayout(new BorderLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        createDisplay();
        
        //Creates game materials
        theGame = new RockPaperShotgun();
    }
    

    
    public void createDisplay()
    {
        //Create Buttons
        rock = new JButton("Rock");
        ActionListener theListener = new rockListener();
        rock.addActionListener(theListener);
        
        paper = new JButton("Paper");
        theListener = new paperListener();
        paper.addActionListener(theListener);
        
        scissors = new JButton("Scissors");
        theListener = new scissorsListener();
        scissors.addActionListener(theListener);
        
        //Create Labels
        currentStatus = new JLabel(" ");
        currentStatus.setHorizontalAlignment(SwingConstants.CENTER);
        
        //Set up Panels
        buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(1,3));
        buttonPanel.add(rock);
        buttonPanel.add(paper);
        buttonPanel.add(scissors);
        
        JPanel StatusPanel = new JPanel();
        StatusPanel.add(currentStatus);
        
        add(buttonPanel,BorderLayout.NORTH);
        add(StatusPanel,BorderLayout.CENTER);
        return;
    }
    
    public class rockListener implements ActionListener {
    
    
        public void actionPerformed(ActionEvent event)
        {
            theGame.setPlayerToRock();
            characterFlag = theGame.executeGame();
            currentStatus.setText(theGame.getStatus());
            if (characterFlag == 'W')
            {
                playerIntScore = playerIntScore + 1;
            }
            else if (characterFlag == 'L')
            {
                computerIntScore = computerIntScore + 1;
            }
            else if (characterFlag == 'D')
            {
                //Do nothing
            }
            else if (characterFlag == 'F')
            {
                System.out.print("Error in Updating Score");
            }
            return;
        }
    }

    public class paperListener implements ActionListener {
    
        public void actionPerformed(ActionEvent event)
        {
            theGame.setPlayerToPaper();
            characterFlag = theGame.executeGame();
            currentStatus.setText(theGame.getStatus());
            if (characterFlag == 'W')
            {
                playerIntScore = playerIntScore + 1;
                
            }
            else if (characterFlag == 'L')
            {
                computerIntScore = computerIntScore + 1;
            }
            else if (characterFlag == 'D')
            {
                //Do nothing
            }
            else if (characterFlag == 'F')
            {
                System.out.print("Error in Updating Score");
            }
            return;
        }
    }
    
    public class scissorsListener implements ActionListener {
    
        public void actionPerformed(ActionEvent event)
        {
            theGame.setPlayerToScissors();
            characterFlag = theGame.executeGame();
            currentStatus.setText(theGame.getStatus());
            if (characterFlag == 'W')
            {
                playerIntScore = playerIntScore + 1;
            }
            else if (characterFlag == 'L')
            {
                computerIntScore = computerIntScore + 1;
            }
            else if (characterFlag == 'D')
            {
                //Do nothing
            }
            else if (characterFlag == 'F')
            {
                System.out.print("Error in Updating Score");
            }
        }
    }    
}


