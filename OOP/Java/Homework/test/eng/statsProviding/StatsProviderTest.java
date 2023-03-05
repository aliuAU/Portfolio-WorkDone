package eng.statsProviding;

import org.testng.annotations.Test;

import static org.junit.jupiter.api.Assertions.*;

class StatsProviderTest {

    @org.junit.jupiter.api.Test
    void add() {
        StatsProvider statsProvider = new StatsProvider();
        statsProvider.add(1d);
        statsProvider.add(2d);

    }

    @org.junit.jupiter.api.Test
    void getMin() {
        StatsProvider statsProvider = new StatsProvider();
        statsProvider.add(9);
        statsProvider.add(3);
        statsProvider.add(19);
        statsProvider.add(2);
        System.out.println(statsProvider.getMin());
    }

    @org.junit.jupiter.api.Test
    void getMax() {
        StatsProvider statsProvider = new StatsProvider();
        statsProvider.add(9);
        statsProvider.add(33);
        statsProvider.add(91);
        statsProvider.add(39);
        System.out.println(statsProvider.getMax());
    }

    @org.junit.jupiter.api.Test
    void getMaxEmpty() {
        StatsProvider statsProvider = new StatsProvider();
        try {
            statsProvider.getMax();
            fail();
        } catch (Exception e) {
            System.out.println("Something went wrong.");
            statsProvider.add(5);
        } finally {
            System.out.println("The try catch is finished");
        }

    }

    @org.junit.jupiter.api.Test
    void getMinEmpty() {
        StatsProvider statsProvider = new StatsProvider();
        try {
            statsProvider.getMin();
            fail();
        } catch (Exception e) {
            System.out.println("Something went wrong.");
            statsProvider.add(5);
        } finally {
            System.out.println("The try catch is finished");
        }

    }


    @org.junit.jupiter.api.Test
    void getCountEmpty() {
        StatsProvider statsProvider = new StatsProvider();
        double expected = 0;
        double actual = statsProvider.getCount();
        assertEquals(expected, actual);


    }

    @org.junit.jupiter.api.Test
    void getCountSmallNumberOfELements() {
        StatsProvider statsProvider = new StatsProvider();
        statsProvider.add(10d);
        double expected = 1;
        double actual = statsProvider.getCount();
        assertEquals(expected, actual);

    }

    @org.junit.jupiter.api.Test
    void getMeanOneValues() {
        StatsProvider statsProvider = new StatsProvider();
        statsProvider.add(5);
        double expected = 5;
        assertEquals(expected, statsProvider.getMean());
    }

    @org.junit.jupiter.api.Test
    void getMeanEmpty() {
        StatsProvider statsProvider = new StatsProvider();
        try {
            statsProvider.getMean();
            fail();
        } catch (Exception x) {

            System.out.println("Something went wrong.");
            statsProvider.add(5);
        } finally {
            System.out.println("The try catch is finished");
        }
    }
    @org.junit.jupiter.api.Test
    void getTrimmedMean(){
        StatsProvider statsProvider = new StatsProvider();
        statsProvider.add(9);
        statsProvider.add(3);
        statsProvider.add(19);
        statsProvider.add(2);
        statsProvider.add(29);
        System.out.println(statsProvider.getTrimmedMean());
    }
}