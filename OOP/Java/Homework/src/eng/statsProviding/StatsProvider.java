package eng.statsProviding;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class StatsProvider {

    private List<Double> values = new ArrayList<>();

    public void add(double value) {
        this.values.add(value);
    }

    public int getCount() {
        return this.values.size();
    }

    public double getMin() {
        return (double) Collections.min(values);
    }

    public double getMax() {
        return (double) Collections.max(values);
    }

    public double getMean() {

        if (this.values.size() == 0)
            throw new ArithmeticException("Stats provider is empty, unable to get mean.");

        double sum = 0;
        for (Double value : values) {
            sum += value;

        }
        double ret = sum / this.values.size();
        return ret;
    }

    public double getTrimmedMean() {
        Collections.sort(values);
        double count = getCount() / 10;
        for (int i = 0; i <= count; i++) {
            double firstvalue = getMin();
            values.remove(firstvalue);
        }

        for (int i = 0; i <= count; i++) {
            double Lastvalue = getMax();
            values.remove(Lastvalue);
        }
        return getMean();
    }

}
