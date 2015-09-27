using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Runtime.InteropServices;

namespace sdk
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        [DllImport(@"D:\Development\Visual Studio Projects\mysdlproject\x64\Debug\GameDll.dll")]
        //[DllImport("GameDll.dll")]
        extern static int CreateApp();

        private void btnClick(object sender, RoutedEventArgs e)
        {
            //int i = GetFour();
            CreateApp();
        }
    }
}
