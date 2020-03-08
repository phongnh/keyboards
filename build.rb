#!/usr/bin/env ruby

class Firmware
  attr_reader :dir

  def initialize(name)
    @dir = File.expand_path(File.join('~', 'src', name.to_s))
  end

  def keyboards
    File.join(dir, 'keyboards')
  end

  def keymap(name, target)
    File.join(keyboards, name.to_s, 'keymaps', target.to_s)
  end
end

class Build
  attr_reader :dir, :keyboard, :target, :firmware, :flash

  def initialize(dir:, keyboard: nil, target: nil, firmware: :qmk_firmware, flash: false)
    @dir      = dir
    @keyboard = keyboard || dir
    @target   = target || 'phongnh'
    @firmware = Firmware.new(firmware)
    @flash    = flash
  end

  def call
    copy
    build
  end

  def self.call(dir:, keyboard: nil, target: nil, firmware: :qmk_firmware)
    new(dir: dir, keyboard: keyboard, target: target, firmware: firmware).call
  end

  private

  def copy
    cmd = "rsync -az #{dir}/ #{firmware.keymap(keyboard, target)}"
    execute cmd
  end

  def build
    cmd = "cd #{firmware.dir} && make #{keyboard}:#{target}"
    execute cmd
  end

  def flash
  end

  def execute(cmd)
    puts "==> Running: #{cmd}"
    system(cmd)
  end
end

KEYBOARDS = { 
  centromere_plus:       'centromere_plus',
  crkbd:                 'crkbd',
  dichotomy:             'dichotomy',
  dichotomy_experiment:  'dichotomy',
  ergodash_ble:          'ergodash/rev1',
  ergodox_ez:            'ergodox_ez',
  ergodox_ez_experiment: 'ergodox_ez',
  hhkb:                  'hhkb',
  iris:                  'keebio/iris',
  katana60:              'katana60',
  preonic:               'preonic',
  redox:                 'redox',
  unigo66:               'unigo66',
  unigo66_experiment:    'unigo66',
  whitefox:              'whitefox',
  whitefox_experiment:   'whitefox'
}

TARGETS = Hash.new { 'phongnh' }.merge(
  dichotomy_experiment:  'phongnh_experiment',
  ergodox_ez_experiment: 'phongnh_experiment',
  unigo66_experiment:    'phongnh_experiment',
  whitefox_experiment:   'phongnh_experiment'
)

FIRMWARES = Hash.new { 'qmk_firmware' }.merge(
  centromere_plus: 'qmk_firmware_spe',
  ergodash_ble:    'qmk_firmware_ble'
)

# builds = [
#   Build.new(dir: :centromere_plus, firmware: :qmk_firmware_spe),
#   Build.new(dir: :crkbd),
#   Build.new(dir: :dichotomy),
#   Build.new(dir: :dichotomy_experiment, keyboard: :dichotomy, target: :phongnh_experiment),
#   Build.new(dir: :ergodash_ble, keyboard: :'ergodash/rev1', firmware: :qmk_firmware_ble),
#   Build.new(dir: :ergodox_ez),
#   Build.new(dir: :ergodox_ez_experiment, keyboard: :ergodox_ez, target: :phongnh_experiment),
#   Build.new(dir: :hhkb),
#   Build.new(dir: :iris, keyboard: :'keebio/iris'),
#   Build.new(dir: :katana60),
#   Build.new(dir: :preonic),
#   Build.new(dir: :redox),
#   Build.new(dir: :unigo66, keyboard: :'sirius/unigo66'),
#   Build.new(dir: :unigo66_experiment, keyboard: :'sirius/unigo66', target: :phongnh_experiment),
#   Build.new(dir: :whitefox),
#   Build.new(dir: :whitefox_experiment, keyboard: :whitefox, target: :phongnh_experiment)
# ].map(&:call)

if ARGV[0] == 'all'
  KEYBOARDS.each_key do |dir|
    Build.call(dir: dir, keyboard: KEYBOARDS[dir], target: TARGETS[dir], firmware: FIRMWARES[dir])
  end
else
  ARGV.map(&:to_sym).each do |dir|
    Build.call(dir: dir, keyboard: KEYBOARDS[dir], target: TARGETS[dir], firmware: FIRMWARES[dir])
  end
end
