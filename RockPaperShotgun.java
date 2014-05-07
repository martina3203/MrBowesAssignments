/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




import java.util.Random;

/**
 *
 * @author blackie
 */
public class RockPaperShotgun {

    /**
     * @param args the command line arguments
     */
    private static int playerPick;
    private static int computerPick;
    private String currentStatus;
    
    
    public char executeGame()
    {
        //This section picks a random number between 1 and 3
        //1 is Rock
        //2 is Paper
        //3 is Scissors
        int max = 3;
        int min = 1;
        //Found on Stack OverFlow by user Greg Case
        Random rand = new Random(); 
        computerPick = rand.nextInt((max-min)+1) + min;
        //If player and computer pick is the same
        if (playerPick == computerPick)
        {
            currentStatus = "It's a tie!";
            return 'D';
        }
        //If player picked Rock
        else if (playerPick == 1)
        {
            //Computer chose Rock
            if (computerPick == 2)
            {
                currentStatus = "Computer used Rock. You lose.";
                return 'L';
            }
            //Computer chose Scissors
            else if (computerPick == 3)
            {
                currentStatus = "Computer used Scissors. You win!";
                return 'W';
            }
        }
        //If player picked Paper
        else if (playerPick == 2)
        {
            //If computer chose Rock
            if (computerPick == 1)
            {
                currentStatus = "Computer used Rock. You Win!";
                return 'W';
            }
            //If computer chose Scissors
            else if (computerPick == 3)
            {
                currentStatus = "Computer used Scissors. You lose!";
                return 'L';
            }
        }
        //If player used Scissors
        else if (playerPick == 3)
        {
            if (computerPick == 1)
            {
                currentStatus = "Computer used Rock. You lose!";
                return 'L';
            }
            else if (computerPick == 2)
            {
                currentStatus = "Computer used Paper. You win!";
                return 'W';
            }
        }
    return 'F';
    }
    
    public void setPlayerToRock()
    {
        playerPick = 1;
        System.out.println("R");
    }
    
    public void setPlayerToPaper()
    {
        playerPick = 2;
        System.out.println("P");
    }
    
    public void setPlayerToScissors()
    {
        playerPick = 3;
        System.out.println("S");
    }
    
    public String getStatus()
    {
        return currentStatus;
    }
    
}
