
public class Shalom_A03Q4
{
    public static abstract class RoundShape
    {
        protected double radius;
        protected double volume;
        protected double surfaceArea;
        /**
         * Constructor for class RoundShape
         */
        public RoundShape()
        {
            //no fields need to be intialized
        }
        
        /**
         * @return      the radius of the object
         */
        public double getRadius()
        {
            return radius;
        }
        
        /**
         * @param  newRadius  new radius for the object
         * @return      the new radius for the object
         */
        public double setRadius(double newRadius)
        {
            radius = newRadius;
            return radius;
        }
        
        //method to be overriden on the child class since its a different formula for both
        public abstract double getSurfaceArea();
        //method to be overriden on the child class since its a differnt formula for both
        public abstract double getVolume();
        
        /**
         * @return      the objects details
         */
        public String toString()
        {
            return "\nRadius: " + Double.toString(radius) +
                    "\nArea: " + Double.toString(getSurfaceArea()) +
                    "\nVolume: " + Double.toString(getVolume());
        }
    }
    
    public static class Sphere extends RoundShape
    {
        /**
         * The constructor accepts and intializes the radius for the Sphere
         */
        public Sphere(double newRadius)
        {
            super();
            radius = newRadius;
        }
        
        /**
         * @return      the surface area of the Sphere
         */
        public double getSurfaceArea()
        {
            return 4 * Math.PI * Math.pow(radius, 2);
        }
        
        /**
         * @return      the volume of the Sphere
         */
        public double getVolume()
        {
            return (Math.PI * Math.pow(radius, 3) * 4) / 3;
        }
        
        /**
         * @return      the shape's name and calls the super class's toString()
         */
        public String toString()
        {
            return "Shape: " + "Sphere" + super.toString();
        }
    }
    
    public static class Cone extends RoundShape
    {
        private double height;
        
        /**
         * The constructor accepts and initializes the radius and height for the Cone.
         */
        public Cone(double newRadius, double newHeight)
        {
            super();
            radius = newRadius;
            height = newHeight;
        }
        
        /**
         * @return      returns the height of the Cone
         */
        public double getHeight()
        {
            return height;
        }
        
        /**
         * @param  newHeigh  the new height in which will be overwritten
         * @return      the new height that was overwritten
         */
        public double setHeight(double newHeight)
        {
            height = newHeight;
            return height;
        }
        
        /**
         * @return      the surface area for the Cone
         */
        public double getSurfaceArea()
        {
            return Math.PI * radius * (radius + Math.sqrt(height * height + radius * radius));
        }
        
        /**
         * @return      the volume for the Cone
         */
        public double getVolume()
        {
            return (Math.PI * Math.pow(radius, 2) * height) / 3;
        }
        
        /**
         * @return      the shape's name and calls the super class's toString()
         */
        public String toString()
        {
            return "Shape: " + "Cone" + "\nHeight: " + Double.toString(height) +
                    super.toString();
        }
    }    
    
    public static void main(String[] args)
    {
        Sphere sphereObject1 = new Sphere(10);
        Sphere sphereObject2 = new Sphere(20);
        
        Cone coneObject1 = new Cone(5, 10);
        Cone coneObject2 = new Cone(10, 20);
        
        System.out.println(sphereObject1 + "\n");
        System.out.println(sphereObject2 + "\n");
        System.out.println(coneObject1 + "\n");
        System.out.println(coneObject2 + "\n");
    }
}