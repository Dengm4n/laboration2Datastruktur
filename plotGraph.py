import subprocess

data_file = "/Users/danielengman/CLionProjects/DoaLabb2/cmake-build-debug/quickSort.data"
output_file = "quickSortConstant.pdf"

gnuplot_script = """
set datafile commentschars "#" # Ignore lines starting with #
set terminal pdf font "cmr"
set output "{output_file}"
set key box
set title "stdSort constant"
set xlabel "N elements"
set ylabel "t [ms]"
set style fill solid 0.5

# Set the range for the x-axis and y-axis

x = 0
f(x) = a*x**2
f1(x) = a1*x*log(x)/log(2)
fit f1(x) "{data_file}" via a1
plot "{data_file}" title "constant" with errorbars, f1(x) smooth csplines t "Fit n log n"
""".format(data_file=data_file, output_file=output_file)

gnuplot_cmd = ['/opt/homebrew/bin/gnuplot']  # replace with the path to your Gnuplot installation

# Call GNU Plot to generate the plot
subprocess.run(gnuplot_cmd, input=gnuplot_script.encode(), check=True)

print("Plot saved as", output_file)