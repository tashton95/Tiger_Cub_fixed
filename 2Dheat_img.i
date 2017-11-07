[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 50
  ny = 50
  nz = 0
  xmax = 186.93
  ymax = 186.93
  zmax = 0
[]

[MeshModifiers]
  [./new_nodeset]
    type = AddExtraNodeset
    new_boundary = 100
    coord = '0 0'
  [../]
[]

[Variables]
  [./temp_x]
    order = FIRST
    family = LAGRANGE
    initial_condition = 100
  [../]
  [./temp_y]
    order = FIRST
    family = LAGRANGE
    initial_condition = 100
  [../]
[]

[Functions]
  [./ImageFunc]
    type = ImageFunction
    origin = '0 0 0'
    component = 2
    dimensions = '186.93 186.93 0'
    file = 'WithVoid10.png'
  [../]
[]

[Kernels]
  [./heat_x]
    type = HeatConduction
    variable = temp_x
  [../]
  [./heat_y]
    type = HeatConduction
    variable = temp_y
  [../]
[]

[BCs]
  [./Periodic]
    [./PeriodicAll]
      variable = 'temp_x temp_y'
      auto_direction = 'x y'
    [../]
  [../]
  [./fix_center_x]
    type = DirichletBC
    variable = temp_x
    value = 100
    boundary = 100
  [../]

  [./fix_center_y]
    type = DirichletBC
    variable = temp_y
    value = 373
    boundary = 100
  [../]
[]

[Materials]
  [./HafniumAluminum]
    type = HfAlMaterial
    block = 0
    interface_cond = 0.0001
  [../]
[]

[Executioner]
  type = Steady
  l_max_its = 30
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart -pc_hypre_boomeramg_strong_threshold'
  petsc_options_value = 'hypre boomeramg 31 0.7'
  l_tol = 1e-9
[]

[Adaptivity]
  initial_steps = 0
  cycles_per_step = 1
  marker = Marker
  initial_marker = Marker
  [./Indicators]
    [./Indicator]
      type = GradientJumpIndicator
      variable = adapt_aux_variable
    [../]
  [../]
  [./Markers]
    [./Marker]
      type = ErrorFractionMarker
      indicator = Indicator
      refine = 0.9
    [../]
  [../]
[]

[Outputs]
  exodus = true
  execute_on = timestep_end
  [./2DHeatConductionExodus]
    output_material_properties = true
    file_base = 2DHeatConductionExodus
    type = Exodus
    show_material_properties = conductivity
  [../]
[]

[ICs]
  [./adapt_aux_variable_IC]
    type = FunctionIC
    function = ImageFunc
    variable = adapt_aux_variable
  [../]
  [./RGB_aux_variable_IC]
    type = FunctionIC
    function = ImageFunc
    variable = RGB_aux_variable
  [../]
[]
