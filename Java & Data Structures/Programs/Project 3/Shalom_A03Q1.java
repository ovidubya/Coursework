public class Shalom_A03Q1
{
    
    /**
     * The following class has the attriubutes of a Cylinder
     */
    public static class Cylinder
    {
        private double radius;
        private double height;
        
        /**
         * The constructor accepts and initializes the 
         * radius and height for the Cylinder
         */
        public Cylinder(double newRadius, double newHeight)
        {
            radius = newRadius;
            height = newHeight;
        }
        
        /**
         * @return      the surface area of a Cylinder
         */
        public double getArea()
        {
           return (2.0 * Math.PI * radius * height) + 
           (2.0 * Math.PI * Math.pow(radius, 2.0));
        }
        
        /**
         * @return      the volume of a Cylinder
         */
        public double getVolume()
        {
            return Math.PI * Math.pow(radius, 2) * height;
        }
        
        /**
         * @return      the radius of the Cylinder
         */
        public double getRadius()
        {
            return radius;
        }
        
        /**
         * @return      the height of the Cylinder
         */
        public double getHeight()
        {
            return height;
        }
        
        /**
         * @param  newHeight  new height to be changed for the Cylinder
         * @return      the new height for the Cylinder
         */
        public void setHeight(double newHeight)
        {
            height = newHeight;
        }
        
        /**
         * @return      the Cylinder's details
         */
        public String toString()
        {
            return "Shape: Cylinder" + "\nradius: " + Double.toString(radius) + 
            "\nheight: " + Double.toString(height) + "\nArea: " + Double.toString(getArea()) +
            "\nVolume: " + Double.toString(getVolume());
        }
    }
    
    public static void main(String args[])
    {
        Cylinder cylinderObj1 = new Cylinder(5, 20);
        Cylinder cylinderObj2 = new Cylinder(10, 25);
        Cylinder cylinderObj3 = new Cylinder(15, 30);
        Cylinder cylinderObj4 = new Cylinder(20, 35);
        System.out.println(cylinderObj1 + "\n");
        System.out.println(cylinderObj2 + "\n");
        System.out.println(cylinderObj3 + "\n");
        System.out.println(cylinderObj4 + "\n");
    }
    
}
