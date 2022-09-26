
public class OppositesAttract {

    /* first idea or instant solution */
    public static boolean isLove1(final int flower1, final int flower2) {
        if (flower1 % 2 == 0 && flower2 % 2 != 0) {
            return true;
        }
        if (flower1 % 2 != 0 && flower2 % 2 == 0) {
            return true;
        }
        return false;
    }

    /* more elegant solution */
    public static boolean isLove2(final int flower1, final int flower2) {
        return flower1 % 2 != flower2 % 2;
    }

}
