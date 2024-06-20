/**
 * Calculate a Radius of a Bouding Box
 */
public class CalcRadiusByBBox {

    /**
     * @see {https://stackoverflow.com/questions/120283/how-can-i-measure-distance-and-create-a-bounding-box-based-on-two-latitudelongi/123305#123305}
     */
    public static double distFrom(double lat1, double lng1, double lat2, double lng2) {
        //double earthRadius = 3958.75;  miles (or 6371.0 kilometers)
        double earthRadius = 6371.0; // miles (or 6371.0 kilometers)
        double dLat = Math.toRadians(lat2 - lat1);
        double dLng = Math.toRadians(lng2 - lng1);
        double sindLat = Math.sin(dLat / 2);
        double sindLng = Math.sin(dLng / 2);
        double a = Math.pow(sindLat, 2) + Math.pow(sindLng, 2)
                * Math.cos(Math.toRadians(lat1)) * Math.cos(Math.toRadians(lat2));
        double c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
        double dist = earthRadius * c;

        return dist;
    }

    /**
     * see {https://stackoverflow.com/questions/15372705/calculating-a-radius-with-longitude-and-latitude}
     */
    public static double coordDistance(double latitude1, double longitude1, double latitude2, double longitude2) {
        return 6371 * Math.acos(
                Math.sin(latitude1) * Math.sin(latitude2)
                        + Math.cos(latitude1) * Math.cos(latitude2) * Math.cos(longitude2 - longitude1));
    }

    public static double calcRadius(double lat1, double lng1, double lat2, double lng2) {
        double teste = Math.min(Math.abs(lat1 - lat2), Math.abs(lng1 - lng2));
        return teste;
    }

    /**
     * see {https://stackoverflow.com/questions/30858889/finding-center-of-set-of-coordinates-using-java}
     */
    public static double calcCenter(double coor1, double coor2) {
        double teste = (coor1 + coor2) / 2;
        return teste;
    }

    private static double milesTokm(double distanceInMiles) {
        return distanceInMiles * 1.60934;
    }

    public static void main(String[] args) {
        System.out.println(
                calcRadius(-7.247743, -34.974011, -7.055965, -34.793018)
        );

        System.out.println(distFrom(-7.247743, -34.974011, -7.055965, -34.793018));

        //System.out.println(coordDistance(-7.247743, -34.974011, -7.055965, -34.793018));
        System.out.println(coordDistance(Math.toRadians(-7.247743), Math.toRadians(-34.974011), Math.toRadians(-7.055965), Math.toRadians(-34.793018)));
        //System.out.println(coordDistance(Math.toDegrees(-7.247743), Math.toDegrees(-34.974011), Math.toDegrees(-7.055965), Math.toDegrees(-34.793018)));


        double latCenter = calcCenter(-7.247743, -7.055965);
        double lngCenter = calcCenter(-34.793018, -34.974011);
        //Esperado: -7.151854, -34.8835145
        System.out.println(latCenter + ", " + lngCenter);

        double maxRadius = distFrom(latCenter, lngCenter, -7.055965, -34.793018);
        System.out.println(maxRadius);

    }
}
